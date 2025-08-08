#include <iostream>
#include "MTexture02.hpp"

// Constants for screen dimensions and window title
constexpr int SCREEN_WIDTH = {640};
constexpr int SCREEN_HEIGHT = {480};
constexpr const char *WINDOW_TITLE{"SDL3 Tutorial 02: Textures and Extension Libraries Example"};


// Function to initialize SDL and create a window
bool init(SDL_Window *&window_prt, SDL_Renderer *&renderer)
{
    // Initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
        return false; // Exit if initialization fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL initialized successfully.\n");

    // Create and render window with the specified title, width, height, and flags
    if (!SDL_CreateWindowAndRenderer(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window_prt, &renderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());

        return false; // Exit if window creation fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window created and renderer initialized successfully.\n");

    return true; // Return success
}

// Function to clean up SDL resources
void cleanup(SDL_Window *&window, SDL_Renderer *&renderer, MTexture *texture)
{

    // Clear the texture resources
    texture->clear();

    // Destroy the renderer
    SDL_DestroyRenderer(renderer);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Renderer destroyed successfully.\n");

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window destroyed successfully.\n");

    // Quit SDL and clean up resources
    SDL_Quit();
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL cleaned up successfully.\n");

    // Reset pointers to nullptr
    window = nullptr;
    renderer = nullptr;
    texture = nullptr;
}

// Function to check media availability (textures, sounds, etc.)
bool checkMediaAvailability(MTexture &texture, SDL_Renderer *&renderer)
{
    bool success{true};

    // Load media resources images, sounds, etc.
    const char *texture_path = "../assets/02img.png";

    // Load the image into a surface
    if (texture.loadTexture(texture_path, renderer) == false)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not texture image: %s\n", SDL_GetError());
        success = false; // Exit if image loading fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture loaded successfully from %s.\n", texture_path);

    return success;
}

// ############################################################################################
int main()
{
    // Declare pointers for the window and renderer
    SDL_Window *pWindow{nullptr};
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

    // Load media resources
    if (!checkMediaAvailability(texture, pRenderer))
    {
        exit_code = 2; // Exit if media availability check fails
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Media availability check failed.\n");
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
        }

        // Fill the background with a white color (inline color setting)
        SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(pRenderer);

        // Render the texture at the center of the screen
        texture.renderTexture((SCREEN_WIDTH - texture.getWidth()) / 2.0f, (SCREEN_HEIGHT - texture.getHeight()) / 2.0f, pRenderer);

        // Present the rendered content to the window
        SDL_RenderPresent(pRenderer);
    }

    // Clean up
    cleanup(pWindow, pRenderer, &texture);

    // Return the exit code: 0 for success, non-zero for failure
    return exit_code;
}