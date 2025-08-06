#include "MTexture.hpp"

// TextureManager's destructor cleans up the texture resource
MTexture::~MTexture() { clear(); }

// ############################################################################################
// TextureManager's loadTexture function loads a texture from a file
bool MTexture::loadTexture(const std::string &filepath, SDL_Renderer *&renderer, bool &remove_background_from_sprite)
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
    else
    {
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture loaded successfully from %s.\n", filepath.c_str());

        if (remove_background_from_sprite)
        {
            // Set the color key for the surface to make a specific color transparent: remove cyan (0x00, 0xFF, 0xFF)
            if (!SDL_SetSurfaceColorKey(loaded_surface, true, SDL_MapSurfaceRGB(loaded_surface, 0x00, 0xFF, 0xFF)))
            {
                SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to set color key for surface: %s\n", SDL_GetError());
            }
            SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Color key set successfully for surface.\n");
        }

        // Create a texture from the loaded surface
        if (texture = SDL_CreateTextureFromSurface(renderer, loaded_surface); texture == nullptr)
        {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to create texture from surface: %s\n", SDL_GetError());
            return false; // Return false if texture creation fails
        }
        else
        {
            SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Loaded dimensions: %dx%d\n", loaded_surface->w, loaded_surface->h);
            // Get the dimensions of the texture
            this->width = loaded_surface->w;
            this->height = loaded_surface->h;
            SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture created successfully from surface with dimensions %dx%d.\n", this->width, this->height);
        }
    }
    // Free the loaded surface as it's no longer needed
    SDL_DestroySurface(loaded_surface);
    loaded_surface = nullptr;

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
    // SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture rendered at position (%f, %f).\n", x, y);
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