#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <string>
#include <iostream>

// Constants for screen dimensions and window title
constexpr int SCREEN_WIDTH = {640};
constexpr int SCREEN_HEIGHT = {480};
constexpr const char *WINDOW_TITLE{"SDL3 Tutorial: Hello SDL3 Example"};

// Function to initialize SDL and create a window
bool init(SDL_Window *&window_prt, SDL_Surface *&screen_surface)
{
    // Initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
        return false; // Exit if initialization fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL initialized successfully.\n");

    // Create a window with the specified title, width, height, and flags
    if (window_prt = SDL_CreateWindow(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL); window_prt == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());

        return false; // Exit if window creation fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window created successfully.\n");

    // Get the window surface
    if (screen_surface = SDL_GetWindowSurface(window_prt); screen_surface == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not get window surface: %s\n", SDL_GetError());

        return false; // Exit if getting the window surface fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window surface obtained successfully.\n");
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "\n"); // Log a newline for better readability

    return true; // Return success
}

// Function to clean up SDL resources
void cleanup(SDL_Window *&window, SDL_Surface *&screen_surface, SDL_Surface *&image_surface)
{
    // Destroy the window surface
    SDL_DestroySurface(screen_surface);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "\nWindow surface freed successfully.\n");

    // Destroy the image surface
    SDL_DestroySurface(image_surface);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Image surface freed successfully.\n");

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Window destroyed successfully.\n");

    // Quit SDL and clean up resources
    SDL_Quit();
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL cleaned up successfully.\n");

    // Reset pointers to nullptr
    window = nullptr;
    screen_surface = nullptr;
    image_surface = nullptr;
}

// Function to load media resources (images, sounds, etc.)
bool loadMedia(SDL_Surface *&image_surface)
{
    bool success{true};

    // Load media resources images, sounds, etc.
    const char *image_path = "../assets/hello-world.bmp";

    // Load the image into a surface
    if (image_surface = SDL_LoadBMP(image_path); image_surface == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not load image: %s\n", SDL_GetError());
        success = false; // Exit if image loading fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Image loaded successfully from %s.\n", image_path);
    return success;
}


int main()
{

    // Declare pointers for the window and surface
    SDL_Window *pWindow{nullptr};
    SDL_Surface *pScreenSurface{nullptr};
    SDL_Surface *pImageSurface{nullptr};

    // Define the destination rectangle for rendering the image scaled
    SDL_Rect destination_rect{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    // Flag to indicate when the application should exit
    bool quit = {false};

    // Exit code
    int exit_code = {0};

    // Initialize SDL and create a window and get the screen surface
    if (!init(pWindow, pScreenSurface))
    {
        exit_code = 1; // Exit if initialization fails
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Initialization failed.\n");
    }

    // Load media resources
    if (!loadMedia(pImageSurface))
    {
        exit_code = 2; // Exit if media loading fails
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Media loading failed.\n");
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

        // Definition of the color to fill the screen (white in this case)
        SDL_Color white_color{255, 255, 255, 255}; 
        
        // Fill the screen surface with a color 
        SDL_FillSurfaceRect(pScreenSurface, nullptr, SDL_MapSurfaceRGB(pScreenSurface, white_color.r, white_color.g, white_color.b));

        // Render the image surface onto the screen surface with scaling
        SDL_BlitSurfaceScaled(pImageSurface, nullptr, pScreenSurface, &destination_rect, SDL_SCALEMODE_LINEAR);

        // Update the window surface to reflect changes
        SDL_UpdateWindowSurface(pWindow);
    }

    // Clean up
    cleanup(pWindow, pScreenSurface, pImageSurface);

    // Return the exit code: 0 for success, non-zero for failure
    return exit_code;
}