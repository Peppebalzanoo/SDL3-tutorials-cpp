#include "MTexture.hpp"

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
        return false; // Return false if loading fails
    }
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture loaded successfully from %s.\n", filepath.c_str());

    // Create a texture from the loaded surface
    if (texture = SDL_CreateTextureFromSurface(renderer, loaded_surface); texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to create texture from surface: %s\n", SDL_GetError());
        return false; // Return false if texture creation fails
    }

    // Get the dimensions of the texture
    this->width = loaded_surface->w;
    this->height = loaded_surface->h;

    // Free the loaded surface as it's no longer needed
    SDL_DestroySurface(loaded_surface);

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture created successfully with dimensions %dx%d.\n", this->width, this->height);
    return true;
}

// ############################################################################################
// TextureManager's renderTexture function renders the texture at a specified position
void MTexture::renderTexture(const float x, const float y, SDL_Renderer *&renderer)
{
    SDL_FRect dstRect{x, y, this->width, this->height};

    // Render the texture to the renderer at the specified position
    if (!SDL_RenderTexture(renderer, this->texture, nullptr, &dstRect))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to render texture: %s\n", SDL_GetError());
    }
    //SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture rendered at position (%f, %f).\n", x, y);
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