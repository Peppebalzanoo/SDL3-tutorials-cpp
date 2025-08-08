#include "MTexture06.hpp"

// TextureManager's destructor cleans up the texture resource
MTexture::~MTexture() { clear(); }

// ############################################################################################
// TextureManager's loadTexture function loads a texture from a file
bool MTexture::loadTexture(const std::string &filepath, SDL_Renderer *&renderer)
{
    // Clear any existing texture before loading a new one
    this->clear();

    // Declare a pointer to hold the loaded surface
    SDL_Surface *loaded_surface{nullptr};

    // Load the texture from the specified file path
    if (loaded_surface = IMG_Load(filepath.c_str()); loaded_surface == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to load texture from %s: %s\n", filepath.c_str(), SDL_GetError());
        SDL_DestroySurface(loaded_surface);
        loaded_surface = nullptr; // Set to nullptr to avoid dangling pointer
        return false;             // Return false if loading fails
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture loaded successfully from %s.\n", filepath.c_str());

    // Set the color key for transparency: this example uses white (0xFF, 0xFF, 0xFF)
    if (SDL_SetSurfaceColorKey(loaded_surface, true, SDL_MapSurfaceRGB(loaded_surface, 0xFF, 0xFF, 0xFF)) == false)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to set color key for surface: %s\n", SDL_GetError());
        SDL_DestroySurface(loaded_surface);
        loaded_surface = nullptr; // Set to nullptr to avoid dangling pointer
        return false;             // Return false if setting color key fails
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Color key set successfully for surface.\n");

    // Create a texture from the loaded surface
    if (texture = SDL_CreateTextureFromSurface(renderer, loaded_surface); texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to create texture from surface: %s\n", SDL_GetError());
        SDL_DestroySurface(loaded_surface);
        loaded_surface = nullptr; // Set to nullptr to avoid dangling pointer
        return false;             // Return false if surface creation fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture created successfully from surface.\n");

    // Get the dimensions of the texture
    this->width = loaded_surface->w;
    this->height = loaded_surface->h;

    // Free the loaded surface as it's no longer needed
    SDL_DestroySurface(loaded_surface);
    loaded_surface = nullptr;

    return true;
}

// ############################################################################################
// TextureManager's renderTexture function renders the texture at a specified position
void MTexture::renderTexture(const float pos_x, const float pos_y, SDL_Renderer *&renderer, const SDL_FRect *clipRect)
{

    SDL_FRect dstRect{pos_x, pos_y, this->width, this->height}; // Declare a rectangle to hold the destination position and size

    // If a clip rectangle is provided, adjust the destination rectangle size
    if (clipRect != nullptr)
    {
        dstRect.w = clipRect->w; // Set the width from the clip rectangle
        dstRect.h = clipRect->h; // Set the height from the clip rectangle
    }

    // Render the texture with the specified renderer, clip rectangle and destination rectangle
    if (!SDL_RenderTexture(renderer, this->texture, clipRect, &dstRect))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to render texture: %s\n", SDL_GetError());
    }
    // SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture rendered at position (%f, %f).\n", x, y);
}

// Function to render the texture with rotation and flipping
void MTexture::renderTexture(const float x, const float y, const float degree, SDL_FlipMode flip_mode, SDL_Renderer *&renderer, const SDL_FRect *clipRect)
{
    SDL_FRect dstRect{x, y, this->width, this->height};

    // Adjust the destination rectangle if a clip rectangle is provided
    if (clipRect != nullptr)
    {
        dstRect.w = clipRect->w;
        dstRect.h = clipRect->h;
    }

    // Define the center point for rotation
    SDL_FPoint center{this->width / 2.f, this->height / 2.f};

    // Render the texture with rotation and flipping
    SDL_RenderTextureRotated(renderer, this->texture, clipRect, &dstRect, degree, &center, flip_mode);
}

// ############################################################################################
// TextureManager's clear function cleans up the texture resource
void MTexture::clear()
{
    SDL_DestroyTexture(this->texture);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture cleared successfully.\n");
    this->texture = nullptr;
    this->width = 0;
    this->height = 0;
}
// ############################################################################################