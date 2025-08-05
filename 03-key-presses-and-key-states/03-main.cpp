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

void cleanup(SDL_Window *&pWindow, SDL_Renderer *&pRenderer, MTexture *texture)
{

    // Clear the texture resources
    texture->clear();

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
    texture = nullptr;
}

bool loadMedia(MTexture &texture, SDL_Renderer *&pRenderer, SDL_Keycode &key_code)
{
    bool success{true};

    if (key_code == SDLK_UP)
        if (texture.loadTexture("../assets/up.png", pRenderer) == false)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load up texture!\n");
            success = false;
        }

    if (key_code == SDLK_DOWN)
        if (texture.loadTexture("../assets/down.png", pRenderer) == false)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load down texture!\n");
            success = false;
        }

    if (key_code == SDLK_LEFT)
        if (texture.loadTexture("../assets/left.png", pRenderer) == false)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load left texture!\n");
            success = false;
        }

    if (key_code == SDLK_RIGHT)
        if (texture.loadTexture("../assets/right.png", pRenderer) == false)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load right texture!\n");
            success = false;
        }

    return success;
}

// ############################################################################################
int main()
{
    // Declare pointers for the window and surface
    SDL_Window *pWindow{nullptr};

    // Renderer used to draw textures to the window
    SDL_Renderer *pRenderer{nullptr};

    // The texture to be rendered
    MTexture texture{};

    // Flag to indicate when the application should exit
    bool quit = {false};

    // Exit code
    int exit_code = {0};

    // Initialize SDL and create a window and get the screen surface
    if (!init(pWindow, pRenderer))
    {
        exit_code = 1; // Exit if initialization fails
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Initialization failed.\n");
    }

    // Create an event structure to handle events
    SDL_Event event;
    SDL_zero(event); // Initialize the event structure

    // Load the default texture
    texture.loadTexture("../assets/loaded.png", pRenderer); // Load the default texture
    // Set the default background color to white
    SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(pRenderer);
    // Render the default texture at the center of the screen
    texture.renderTexture((SCREEN_WIDTH - texture.getWidth()) / 2.0f, (SCREEN_HEIGHT - texture.getHeight()) / 2.0f, pRenderer); // Render the texture at the center of the screen
    // Present the cleared renderer
    SDL_RenderPresent(pRenderer); // Present the cleared renderer

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
            else if (event.type == SDL_EVENT_KEY_DOWN)
            {
                if (event.key.key == SDLK_UP || event.key.key == SDLK_DOWN || event.key.key == SDLK_LEFT || event.key.key == SDLK_RIGHT)
                {
                    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Key pressed: %s\n", SDL_GetKeyName(event.key.key));

                    // Set the texture based on the key pressed
                    if (!loadMedia(texture, pRenderer, event.key.key))
                    {
                        exit_code = 2; // Exit if media loading fails
                        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Media loading failed.\n");
                    }

                    // Set the default background color to white
                    SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(pRenderer);

                    // Render the texture at the center of the screen
                    texture.renderTexture((SCREEN_WIDTH - texture.getWidth()) / 2.0f, (SCREEN_HEIGHT - texture.getHeight()) / 2.0f, pRenderer);

                    // Present the rendered content to the window
                    SDL_RenderPresent(pRenderer);
                }
                else
                {
                    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unsupported key pressed: %s\n", SDL_GetKeyName(event.key.key));
                }
            }
        }
    }

    // Clean up
    cleanup(pWindow, pRenderer, &texture);

    // Return the exit code: 0 for success, non-zero for failure
    return exit_code;
}