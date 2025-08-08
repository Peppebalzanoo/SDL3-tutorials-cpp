#include "MTexture06.hpp"
#include <iostream>

// Constants for screen dimensions and window title
constexpr int SCREEN_WIDTH{640};
constexpr int SCREEN_HEIGHT{480};
constexpr const char *WINDOW_TITLE{"SDL3 Tutorial 06: Rotation and Flipping Example"};

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

// Function to check media availability (textures, sounds, etc.)
bool checkMediaAvailability(MTexture &texture, SDL_Renderer *&pRenderer)
{
    bool success{true};

    if (!texture.loadTexture("../assets/06arrow.png", pRenderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load background texture with color key!\n");
        success = false;
    }

    return success;
}

int main()
{
    // Declare pointers for the window and renderer
    SDL_Window *pWindow{nullptr};
    SDL_Renderer *pRenderer{nullptr};

    MTexture texture{}; // The texture to be rendered

    SDL_Event event; // Create an event structure to handle events
    SDL_zero(event); // Initialize the event structure

    bool quit = {false}; // Flag to indicate when the application should exit
    int exit_code = {0}; // Exit code

    double degrees = 0.0;                   // Initialize rotation angle
    SDL_FlipMode flip_mode = SDL_FLIP_NONE; // Initialize flip mode

    // Initialize SDL and create a window and get the screen surface
    if (!init(pWindow, pRenderer))
    {
        exit_code = 1; // Exit if initialization fails
        quit = true;   // Set quit flag to true
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Initialization failed.\n");
        SDL_Delay(3000); // Delay for 3 seconds to allow the user to see the error
    }
    else
    {
        // Check if the media loading is successful
        if (!checkMediaAvailability(texture, pRenderer))
        {
            exit_code = 2; // Exit if media availability check fails
            quit = true;   // Set quit flag to true
            SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Media availability check failed.\n");
            SDL_Delay(3000); // Delay for 3 seconds to allow the user to see the error
        }
        else
        {
            // Main loop: keep running until the quit flag is set
            while (!quit)
            {
                while (SDL_PollEvent(&event)) // Events Loop: Poll for events
                {
                    // Check if the quit event is triggered
                    if (event.type == SDL_EVENT_QUIT)
                    {
                        quit = true; // Set quit flag to true
                    }
                    else if (event.type == SDL_EVENT_KEY_DOWN) // Check for key down events
                    {
                        // Handle key presses for rotation and flipping
                        switch (event.key.key)
                        {
                        case SDLK_LEFT:       // Rotate left
                            degrees -= 30.0f; // Rotate left by 30 degrees
                            break;
                        case SDLK_RIGHT:      // Rotate right
                            degrees += 30.0f; // Rotate right by 30 degrees
                            break;

                        case SDLK_UP: // Flip vertically
                            flip_mode = SDL_FLIP_VERTICAL;
                            break;

                        case SDLK_DOWN: // Flip horizontally
                            flip_mode = SDL_FLIP_HORIZONTAL;
                            break;

                        default:
                            degrees = 0.0;             // Reset rotation angle
                            flip_mode = SDL_FLIP_NONE; // Reset flip mode
                            break;
                        }
                    }
                }

                // Set the default background color to white (inline color setting)
                SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(pRenderer);

                float pos_center_x = (SCREEN_WIDTH - texture.getWidth()) / 2.0f;
                float pos_center_y = (SCREEN_HEIGHT - texture.getHeight()) / 2.0f;
                texture.renderTexture(pos_center_x, pos_center_y, degrees, flip_mode, pRenderer);

                // Present the rendered content to the window
                SDL_RenderPresent(pRenderer);
            }
        }
    }
    // Clean up
    cleanup(pWindow, pRenderer, &texture);

    // Return the exit code: 0 for success, non-zero for failure
    return exit_code;
}