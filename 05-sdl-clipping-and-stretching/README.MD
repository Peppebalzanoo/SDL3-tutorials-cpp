# SDL3 Tutorial 05: Clipping and Stretching

## Overview

This tutorial demonstrates **texture clipping** and **stretching** techniques in SDL3. Clipping allows you to render only specific portions of a texture (like sprites from a sprite sheet), while stretching enables you to resize textures during rendering without modifying the original image data.

## What This Program Does

1. **Window Creation**: Creates a 640x480 SDL3 window with a renderer
2. **Texture Clipping**: Demonstrates how to render specific rectangular regions from a larger texture
3. **Texture Stretching**: Shows how to scale textures to different sizes during rendering
4. **Multiple Rendering**: Displays the same sprite in different locations with various transformations
5. **Sprite Sheet Usage**: Uses a texture containing multiple sprites arranged in a grid

## Key Features

### Texture Clipping Technology
- **Clip Rectangles**: Uses `SDL_FRect` to define which portion of the texture to render
- **Sprite Extraction**: Extracts individual sprites from a larger sprite sheet
- **Precise Positioning**: Renders clipped textures at exact screen coordinates

### Texture Stretching System
The program demonstrates two rendering modes:
- **Normal Rendering**: Displays sprites at their original 100x100 pixel size
- **Stretched Rendering**: Displays the same sprites scaled to 50x100 pixels (half width, same height)

### Enhanced MTexture Class
The custom `MTexture` class now includes:
- **Overloaded Rendering**: Two `renderTexture` methods - one for normal rendering, one for stretched rendering
- **Clipping Support**: Both methods accept optional `SDL_FRect*` parameters for clipping
- **Flexible Scaling**: Stretching method allows independent width and height scaling

## File Structure

```
05-sdl-clipping-and-stretching/
├── 05-main.cpp          # Main program file
├── MTexture05.hpp       # Custom texture class header with clipping/stretching support
├── Mtexture05.cpp       # Custom texture class implementation
├── build.bat            # Build script
└── README.md            # This file

../                      # Parent directory contains:
├── main.exe             # Compiled executable (shared across tutorials)
├── SDL3.dll             # SDL3 runtime library
└── SDL3_image.dll       # SDL3_image runtime library
```

## Required Assets

The program expects the following asset in the `../assets/` directory:
- `05dots.png` - Original sprite sheet containing multiple colored dots arranged in a 2x2 grid (200x200 pixels total, each sprite 100x100)

**Note**: The program references `04dots.png` in the code but should use `05dots.png` according to the naming convention.

## Rendering Layout

The program displays 8 sprites total:
- **4 Corners (Normal Size)**: One sprite from each quadrant of the sprite sheet at original 100x100 size
- **4 Corners (Stretched)**: The same sprites stretched to 50x100 size, positioned below/beside the normal ones

### Sprite Positions
- **Top-Left Quadrant**: Renders at (0,0) normal and (0,100) stretched
- **Top-Right Quadrant**: Renders at (540,0) normal and (590,100) stretched  
- **Bottom-Left Quadrant**: Renders at (0,380) normal and (0,280) stretched
- **Bottom-Right Quadrant**: Renders at (540,380) normal and (590,280) stretched

## Building

Run the build script:
```bash
build.bat
```

Or compile manually:
```bash
g++ -std=c++17 05-main.cpp Mtexture05.cpp -I../lib/SDL3-3.2.18/x86_64-w64-mingw32/include -I../lib/SDL3_image-3.2.4/x86_64-w64-mingw32/include -L../lib/SDL3-3.2.18/x86_64-w64-mingw32/lib -L../lib/SDL3_image-3.2.4/x86_64-w64-mingw32/lib -lSDL3 -lSDL3_image -o main.exe
```

## Running

1. Ensure `SDL3.dll` and `SDL3_image.dll` are in the same directory as the executable
2. Ensure the asset `05dots.png` is available at `../assets/05dots.png`
3. Run the executable:
   ```bash
   ./main.exe
   ```

## Controls

- **Window Close Button**: Exit the application
- **Alt+F4**: Exit the application

## Learning Objectives

After completing this tutorial, you will understand:
1. How to implement texture clipping using SDL_FRect
2. How to stretch/scale textures during rendering
3. How to work with sprite sheets and extract individual sprites
4. How to create flexible rendering methods that support both clipping and stretching
5. How to position multiple sprites efficiently on screen

## Code Structure

### Helper Functions
- `clipTexture()`: Renders a clipped texture at normal size
- `stretchTexture()`: Renders a clipped texture with scaling
- `init()`: Initializes SDL3 and creates window/renderer
- `cleanup()`: Properly destroys all SDL3 resources
- `checkMediaAvailability()`: Loads and validates texture assets

### Main Loop
The main loop continuously:
1. Processes SDL events (quit detection)
2. Clears the screen with white background
3. Renders 8 sprites (4 normal + 4 stretched) using the helper functions
4. Presents the final frame to the screen

## Dependencies

- SDL3 (Simple DirectMedia Layer 3)
- SDL3_image extension library
- Standard C++ library

## Learning Reference and Attribution

This tutorial represents my personal implementation and interpretation of SDL3 concepts. While learning SDL3, I referenced educational content from Lazy Foo' Productions to understand core programming concepts, but this project contains:

- **Original Code**: My own implementation and interpretation of SDL3 concepts
- **Original Assets**: All graphical resources are either my original creations or sourced from free-licensed materials
- **No Redistribution**: No source code, assets, or copyrighted material from Lazy Foo' Productions has been included

**All images and resources in this project are original creations or free-licensed materials. No copyrighted images from external tutorials have been used.**

## License

This is my personal educational project implementing SDL3 concepts. All code and assets are original or free-licensed. Please refer to SDL3's license for