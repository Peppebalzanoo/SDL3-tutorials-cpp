#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>

class MTexture
{
private:
    SDL_Texture *texture; // Pointer to the texture object
    float width;            // Width of the texture
    float height;           // Height of the texture

public:
    // Constructor to initialize resources
    MTexture() : texture(nullptr), width(0), height(0) {};

    // Destructor to clean up resources
    ~MTexture();

    // Function to load a texture from a file
    bool loadTexture(const std::string &file_path, SDL_Renderer *&renderer);

    // Function to render the texture at a specific position
    void renderTexture(const float x, const float y, SDL_Renderer *&renderer);

    // Function to clear up the texture resources
    void clear();

    // Getter for the texture pointer inline for efficiency
    inline const float getWidth() const { return width; }   // Getter for texture width
    inline const float getHeight() const { return height; } // Getter for texture height
};
