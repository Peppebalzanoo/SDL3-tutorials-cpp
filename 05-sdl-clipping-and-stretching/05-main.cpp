#include "MTexture05.hpp"
#include <iostream>

// Constants for screen dimensions and window title
constexpr int SCREEN_WIDTH{640};
constexpr int SCREEN_HEIGHT{480};
constexpr const char *WINDOW_TITLE{"SDL3 Tutorial 05: Clipping and Stretching Example"};

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

    if (!texture.loadTexture("../assets/05dots.png", pRenderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load background texture with color key!\n");
        success = false;
    }

    return success;
}

void clipTexture(float sprite_pos_x, float sprite_pos_y, const float SPRITE_SIZE, float pos_x, float pos_y, MTexture &texture, SDL_Renderer *&pRenderer)
{
    // Initialize the clip rectangle with the specified dimensions for clipping
    SDL_FRect clipRect{sprite_pos_x, sprite_pos_y, SPRITE_SIZE, SPRITE_SIZE};

    // Render the texture at the specified position with the clip rectangle
    texture.renderTexture(pos_x, pos_y, pRenderer, &clipRect);
}

void stretchTexture(float sprite_pos_x, float sprite_pos_y, const float SPRITE_SIZE, float pos_x, float pos_y, float stretch_w, float stretch_h, MTexture &texture, SDL_Renderer *&pRenderer)
{
    // Initialize the clip rectangle with the specified dimensions for clipping
    SDL_FRect clipRect{sprite_pos_x, sprite_pos_y, SPRITE_SIZE, SPRITE_SIZE};

    // Render the texture at the specified position with the clip rectangle
    texture.renderTexture(pos_x, pos_y, stretch_w, stretch_h, pRenderer, &clipRect);
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
                }

                // Set the default background color to white (inline color setting)
                SDL_SetRenderDrawColor(pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(pRenderer);

                constexpr float SPRITE_SIZE = 100.f;
                float sprite_pos_x = 0.f; // Sprite position X
                float sprite_pos_y = 0.f; // Sprite position Y
                float rect_pos_x = 0.f;   // Rectangle position X
                float rect_pos_y = 0.f;   // Rectangle position Y
                float stretch_w = 0.f;    // Stretch width
                float stretch_h = 0.f;    // Stretch height

                // Top-left sprite without stretching
                sprite_pos_x = 0.f; // Sprite position X
                sprite_pos_y = 0.f; // Sprite position Y
                rect_pos_x = 0.f;   // Rectangle position X
                rect_pos_y = 0.f;   // Rectangle position Y
                clipTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, texture, pRenderer);
                // Top-left sprite with stretching
                stretch_w = SPRITE_SIZE * 0.5; // Stretch width
                stretch_h = SPRITE_SIZE * 1.0; // Stretch height
                rect_pos_x = 0.f;              // Rectangle position X
                rect_pos_y = stretch_h;        // Rectangle position Y
                stretchTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, stretch_w, stretch_h, texture, pRenderer);

                // Top-right sprite without stretching
                sprite_pos_x = SPRITE_SIZE;              // Sprite position X
                sprite_pos_y = 0.f;                      // Sprite position Y
                rect_pos_x = SCREEN_WIDTH - SPRITE_SIZE; // Rectangle position X
                rect_pos_y = 0.f;                        // Rectangle position Y
                clipTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, texture, pRenderer);
                // Top-right sprite with stretching
                stretch_w = SPRITE_SIZE * 0.5;         // Stretch width
                stretch_h = SPRITE_SIZE * 1.0;         // Stretch height
                rect_pos_x = SCREEN_WIDTH - stretch_w; // Rectangle position X
                rect_pos_y = stretch_h;                // Rectangle position Y
                stretchTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, stretch_w, stretch_h, texture, pRenderer);

                // Bottom-left sprite without stretching
                sprite_pos_x = 0.f;                       // Sprite position X
                sprite_pos_y = SPRITE_SIZE;               // Sprite position Y
                rect_pos_x = 0.f;                         // Rectangle position X
                rect_pos_y = SCREEN_HEIGHT - SPRITE_SIZE; // Rectangle position Y
                clipTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, texture, pRenderer);
                // Bottom-left sprite with stretching
                stretch_w = SPRITE_SIZE * 0.5;              // Stretch width
                stretch_h = SPRITE_SIZE * 1.0;              // Stretch height
                rect_pos_x = 0.f;                           // Rectangle position X
                rect_pos_y = SCREEN_HEIGHT - 2 * stretch_h; // Rectangle position Y
                stretchTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, stretch_w, stretch_h, texture, pRenderer);

                // Bottom-right sprite without stretching
                sprite_pos_x = SPRITE_SIZE;               // Sprite position X
                sprite_pos_y = SPRITE_SIZE;               // Sprite position Y
                rect_pos_x = SCREEN_WIDTH - SPRITE_SIZE;  // Rectangle position X
                rect_pos_y = SCREEN_HEIGHT - SPRITE_SIZE; // Rectangle position Y
                clipTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, texture, pRenderer);
                // Bottom-right sprite with stretching
                stretch_w = SPRITE_SIZE * 0.5;              // Stretch width
                stretch_h = SPRITE_SIZE * 1.0;              // Stretch height
                rect_pos_x = SCREEN_WIDTH - stretch_w;      // Rectangle position X
                rect_pos_y = SCREEN_HEIGHT - 2 * stretch_h; // Rectangle position Y
                stretchTexture(sprite_pos_x, sprite_pos_y, SPRITE_SIZE, rect_pos_x, rect_pos_y, stretch_w, stretch_h, texture, pRenderer);

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