#include "MTexture.hpp"
#include <iostream>

// Constants for screen dimensions and window title
constexpr int SCREEN_WIDTH{640};
constexpr int SCREEN_HEIGHT{480};
constexpr const char *WINDOW_TITLE{"SDL3 Tutorial: Color Keying Example"};

// Function to initialize SDL and create a window
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

// Function to clean up SDL resources
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

// Function to load media resources (images, sounds, etc.)
bool loadMedia(MTexture &bg_texture, MTexture &foo_texture, SDL_Renderer *&pRenderer, bool &remove_background_from_sprite)
{
    bool success{true};

    if (!remove_background_from_sprite)
    {
        if (!bg_texture.loadTexture("../assets/04background0.png", pRenderer, remove_background_from_sprite))
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load background texture!\n");
            success = false;
        }
    }
    else
    {
        // Change background texture if remove_background_from_sprite is true.
        // New texture without text: "Press a key to remove background from sprite"
        if (!bg_texture.loadTexture("../assets/04background1.png", pRenderer, remove_background_from_sprite))
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load background texture with color key!\n");
            success = false;
        }
    }

    if (!foo_texture.loadTexture("../assets/04sprite.png", pRenderer, remove_background_from_sprite))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load sprite texture!\n");
        success = false;
    }

    return success;
}

int main()
{
    // Declare pointers for the window and renderer
    SDL_Window *pWindow{nullptr};
    SDL_Renderer *pRenderer{nullptr};

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

    bool remove_background_from_sprite = false; // Flag to indicate if the background should be removed

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
            else
            {
                if (event.type == SDL_EVENT_KEY_DOWN) // Check if a key is pressed
                {
                    remove_background_from_sprite = true; // Set the flag to remove background
                }

                // Set the texture based on the key pressed
                if (!loadMedia(bg_texture, foo_texture, pRenderer, remove_background_from_sprite))
                {
                    exit_code = 2; // Exit if media loading fails
                    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Media loading failed.\n");
                }

                // Set the default background color to white (inline color setting)
                SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(pRenderer);

                // Render the texture at the center of the screen
                bg_texture.renderTexture(0, 0, pRenderer);
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