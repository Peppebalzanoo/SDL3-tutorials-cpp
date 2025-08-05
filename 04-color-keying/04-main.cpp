#include "MTexture.hpp"
#include <iostream>

constexpr int SCREEN_WIDTH{640};
constexpr int SCREEN_HEIGHT{480};
constexpr const char *WINDOW_TITLE{"SDL3 Tutorial: Key Presses and Key States"};

bool init(SDL_Window *&pWindow, SDL_Renderer *&pRenderer)
{
    // Initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
        return false; // Exit if initialization fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL initialized successfully.\n");

    // Create and render window with the specified title, width, height, and flags
    if (!SDL_CreateWindowAndRenderer(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, 0, &pWindow, &pRenderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());

        return false; // Exit if window creation fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window created and renderer initialized successfully.\n");

    return true; // Return success
}

void cleanup(SDL_Window *&pWindow, SDL_Renderer *&pRenderer, MTexture *bg_texture, MTexture *foo_texture)
{

    // Clear the texture resources
    bg_texture->clear();
    foo_texture->clear();

    // Destroy the renderer
    SDL_DestroyRenderer(pRenderer);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Renderer destroyed successfully.\n");

    // Close and destroy the window
    SDL_DestroyWindow(pWindow);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window destroyed successfully.\n");

    // Quit SDL and clean up resources
    SDL_Quit();
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL cleaned up successfully.\n");

    // Reset pointers to nullptr
    pWindow = nullptr;
    pRenderer = nullptr;
    bg_texture = nullptr;
}

bool loadMedia(MTexture &bg_texture, MTexture &foo_texture, SDL_Renderer *&pRenderer)
{
    bool success{true};

    if (!bg_texture.loadTexture("../assets/background.png", pRenderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load background texture!\n");
        success = false;
    }

    if (!foo_texture.loadTexture("../assets/foo.png", pRenderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load foo texture!\n");
        success = false;
    }

    return success;
}

// ############################################################################################
int main()
{
    SDL_Window *pWindow{nullptr};     // Declare pointers for the window and surface
    SDL_Renderer *pRenderer{nullptr}; // Renderer used to draw textures to the window

    // The texture to be rendered
    MTexture bg_texture{};
    MTexture foo_texture{};

    bool quit = {false}; // Flag to indicate when the application should exit

    int exit_code = {0}; // Exit code

    // Initialize SDL and create a window and get the screen surface
    if (!init(pWindow, pRenderer))
    {
        exit_code = 1; // Exit if initialization fails
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Initialization failed.\n");
    }

    // Create an event structure to handle events
    SDL_Event event;
    SDL_zero(event); // Initialize the event structure

    // Main loop: keep running until the quit flag is set
    while (!quit)
    {
        while (SDL_PollEvent(&event)) // Events Loop: Poll for events
        {
            // Check if the quit event is triggered
            if (event.type == SDL_EVENT_QUIT)
            {
                quit = true; // Set the quit flag to true
            }
            // Check if a key is pressed
            else
            {
                SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Key pressed: %s\n", SDL_GetKeyName(event.key.key));

                // Set the texture based on the key pressed
                if (!loadMedia(bg_texture, foo_texture, pRenderer))
                {
                    exit_code = 2; // Exit if media loading fails
                    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Media loading failed.\n");
                }

                // Set the default background color to white
                SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(pRenderer);

                // Render the texture at the center of the screen
                bg_texture.renderTexture(0.0f, 0.0f, pRenderer);
                foo_texture.renderTexture((SCREEN_WIDTH - foo_texture.getWidth()) / 2, (SCREEN_HEIGHT - foo_texture.getHeight()) / 2, pRenderer);

                // Present the rendered content to the window
                SDL_RenderPresent(pRenderer);
            }
        }
    }

    // Clean up
    cleanup(pWindow, pRenderer, &bg_texture, &foo_texture);

    // Return the exit code: 0 for success, non-zero for failure
    return exit_code;
}