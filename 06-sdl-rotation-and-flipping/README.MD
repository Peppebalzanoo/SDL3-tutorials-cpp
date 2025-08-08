# SDL3 Tutorial 06: Rotation and Flipping

## Overview

This tutorial demonstrates **texture rotation** and **flipping** techniques in SDL3. These transformations allow you to dynamically rotate textures by any angle and flip them horizontally or vertically during rendering, which is essential for creating animated sprites, directional indicators, and visual effects in games.

## What This Program Does

1. **Window Creation**: Creates a 640x480 SDL3 window with a renderer
2. **Texture Rotation**: Demonstrates how to rotate textures by specified angles in real-time
3. **Texture Flipping**: Shows how to flip textures horizontally and vertically
4. **Interactive Controls**: Responds to keyboard input to control rotation and flipping
5. **Center-Based Rotation**: Rotates textures around their center point for natural movement

## Key Features

### Texture Rotation Technology
- **Angle Control**: Uses `SDL_RenderTextureRotated()` for precise angle-based rotation
- **Center Point Rotation**: Rotates textures around their geometric center
- **Real-Time Updates**: Smooth rotation updates based on user input
- **Degree-Based System**: Uses floating-point degrees for rotation precision

### Texture Flipping System
The program supports three flip modes:
- **No Flip** (`SDL_FLIP_NONE`): Normal texture rendering
- **Horizontal Flip** (`SDL_FLIP_HORIZONTAL`): Mirrors texture left-to-right
- **Vertical Flip** (`SDL_FLIP_VERTICAL`): Mirrors texture top-to-bottom

### Enhanced MTexture Class
The custom `MTexture` class now includes:
- **Overloaded Rendering**: Two `renderTexture` methods - one standard, one with rotation/flipping
- **Rotation Support**: Accepts degree parameters for texture rotation
- **Flip Mode Support**: Accepts `SDL_FlipMode` enumeration for texture flipping
- **Center Point Calculation**: Automatically calculates rotation center based on texture dimensions

## File Structure

```
06-sdl-rotation-and-flipping/
├── 06-main.cpp          # Main program file
├── MTexture06.hpp       # Custom texture class header with rotation/flipping support
├── Mtexture06.cpp       # Custom texture class implementation
├── build.bat            # Build script
└── README.md            # This file

../                      # Parent directory contains:
├── main.exe             # Compiled executable (shared across tutorials)
├── SDL3.dll             # SDL3 runtime library
└── SDL3_image.dll       # SDL3_image runtime library
```

## Required Assets

The program expects the following asset in the `../assets/` directory:
- `06arrow.png` - Original arrow image with white background (for color keying) created specifically for this project

**Note**: The texture uses white (0xFF, 0xFF, 0xFF) as the transparent color key to remove the background.

## Controls

- **LEFT Arrow**: Rotate counterclockwise by 30 degrees
- **RIGHT Arrow**: Rotate clockwise by 30 degrees
- **UP Arrow**: Flip vertically (`SDL_FLIP_VERTICAL`)
- **DOWN Arrow**: Flip horizontally (`SDL_FLIP_HORIZONTAL`)
- **Any Other Key**: Reset to normal (0° rotation, no flip)
- **Window Close Button**: Exit the application

## Rendering Behavior

### Rotation System
- **Initial State**: Arrow displays at 0 degrees (normal orientation)
- **Rotation Increment**: Each left/right key press rotates by 30 degrees
- **Continuous Rotation**: Rotation values can exceed 360° and continue accumulating
- **Center-Based**: All rotations occur around the texture's center point

### Flipping System
- **Immediate Effect**: Flip modes take effect immediately when keys are pressed
- **Independent Operation**: Flipping works independently of rotation
- **State Persistence**: Flip mode persists until reset or changed

### Visual Layout
- **Centered Display**: The arrow texture is always rendered at the center of the screen
- **Dynamic Positioning**: Center position is calculated based on screen dimensions and texture size
- **White Background**: Uses a clean white background to highlight the transformations

## Building

Run the build script:
```bash
build.bat
```

Or compile manually:
```bash
g++ -std=c++17 06-main.cpp Mtexture06.cpp -I../lib/SDL3-3.2.18/x86_64-w64-mingw32/include -I../lib/SDL3_image-3.2.4/x86_64-w64-mingw32/include -L../lib/SDL3-3.2.18/x86_64-w64-mingw32/lib -L../lib/SDL3_image-3.2.4/x86_64-w64-mingw32/lib -lSDL3 -lSDL3_image -o main.exe
```

## Running

1. Ensure `SDL3.dll` and `SDL3_image.dll` are in the same directory as the executable
2. Ensure the asset `06arrow.png` is available at `../assets/06arrow.png`
3. Run the executable:
   ```bash
   ./main.exe
   ```

## Learning Objectives

After completing this tutorial, you will understand:
1. How to implement texture rotation using `SDL_RenderTextureRotated()`
2. How to use `SDL_FlipMode` enumeration for texture flipping
3. How to calculate center points for natural rotation behavior
4. How to handle real-time input for dynamic transformations
5. How to combine rotation and flipping effects
6. How to create responsive visual feedback for user interactions

## Code Structure

### Key Components
- **Rotation Variable**: `double degrees` tracks current rotation angle
- **Flip Variable**: `SDL_FlipMode flip_mode` tracks current flip state
- **Event Handling**: Keyboard input modifies rotation and flip variables
- **Center Calculation**: Dynamic center positioning for screen-centered rendering

### Transformation Pipeline
1. **Input Processing**: Keyboard events modify transformation parameters
2. **Background Clear**: White background is cleared each frame
3. **Position Calculation**: Center position calculated based on texture dimensions
4. **Transform Rendering**: Texture rendered with current rotation and flip settings
5. **Frame Presentation**: Final result presented to screen

### MTexture Class Methods
- `renderTexture(x, y, renderer, clipRect)`: Standard rendering without transformations
- `renderTexture(x, y, degree, flip_mode, renderer, clipRect)`: Advanced rendering with rotation and flipping

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

This is my personal educational project implementing SDL3 concepts. All code and assets are original or free-licensed. Please refer to SDL3's license for library usage