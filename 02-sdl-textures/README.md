# SDL3 Tutorial: SDL Textures and Extension Libraries

## Overview

This project demonstrates how to work with textures and extension libraries in SDL3. It builds upon basic SDL3 concepts by introducing hardware-accelerated rendering with textures instead of software surfaces, and shows how to use SDL3_image extension library for loading various image formats.

## What This Tutorial Covers

### Key Concepts Learned

1. **Hardware-Accelerated Rendering**: Transition from software surfaces to hardware-accelerated textures using SDL_Renderer
2. **Extension Libraries**: Integration of SDL3_image for loading PNG files (and other formats)
3. **Custom Texture Class**: Implementation of a reusable `MTexture` class for texture management
4. **Centered Rendering**: Positioning textures at the center of the screen

### Technical Features

- **SDL_Renderer**: Uses hardware acceleration for better performance compared to surface blitting
- **SDL3_image Integration**: Loads PNG images using the SDL3_image extension library
- **Object-Oriented Design**: Custom `MTexture` class encapsulates texture operations
- **Resource Management**: Proper cleanup of textures, renderer, and window resources
- **Error Handling**: Comprehensive error checking with SDL logging

## File Structure

```
02-sdl-textures/
├── 02-main.cpp          # Main application file
├── MTexture02.hpp         # Custom texture class header
├── MTexture02.cpp         # Custom texture class implementation
├── build.bat            # Build script for Windows
└── README.md            # This file

../                      # Parent directory contains:
├── main.exe             # Compiled executable (shared across tutorials)
├── SDL3.dll             # SDL3 runtime library
└── SDL3_image.dll       # SDL3_image runtime
```

## Assets

This tutorial uses the following original asset from the shared assets directory:
- `../assets/02img.png` - Original PNG image created specifically for this project

## Code Breakdown

### Main Components

1. **Initialization (`init` function)**:
   - Initializes SDL3 video subsystem
   - Creates window and renderer in one call using `SDL_CreateWindowAndRenderer`
   - Returns success/failure status

2. **Media Loading (`loadMedia` function)**:
   - Uses custom `MTexture` class to load PNG image
   - Loads image from `../assets/texture.png`
   - Returns success/failure status

3. **Main Loop**:
   - Event handling for window close events
   - Clear screen with white background
   - Render texture centered on screen
   - Present rendered frame

4. **Cleanup (`cleanup` function)**:
   - Destroys texture resources
   - Destroys renderer and window
   - Quits SDL3 and resets pointers

### MTexture Class Features

The custom `MTexture` class provides:
- **Texture Loading**: `loadTexture()` method using SDL3_image
- **Rendering**: `renderTexture()` method for positioned drawing
- **Resource Management**: Automatic cleanup in destructor
- **Dimension Access**: Getter methods for width and height
- **Manual Cleanup**: `clear()` method for explicit resource release

## Key Differences from Previous Tutorial

1. **Renderer vs Surface**: Uses `SDL_Renderer` for hardware acceleration instead of `SDL_Surface`
2. **Texture vs Surface**: Works with `SDL_Texture` objects instead of `SDL_Surface`
3. **Extension Library**: Integrates SDL3_image for PNG support (previous tutorial used BMP)
4. **Object-Oriented**: Introduces custom class for better code organization
5. **Centered Positioning**: Calculates center position for texture placement

## Building and Running

### Prerequisites
- SDL3 development libraries
- SDL3_image extension library
- C++ compiler (MinGW-w64 or Visual Studio)

### Build Instructions
```bash
# Using the provided build script
./build.bat

# Or manually with g++
g++ -I./lib/SDL3-3.2.18/x86_64-w64-mingw32/include \
    -I./lib/SDL3_image-3.2.4/x86_64-w64-mingw32/include \
    -L./lib/SDL3-3.2.18/x86_64-w64-mingw32/lib \
    -L./lib/SDL3_image-3.2.4/x86_64-w64-mingw32/lib \
    -o main.exe 02-main.cpp MTexture02.cpp \
    -lSDL3 -lSDL3_image
```

### Running
```bash
./main.exe
```

## Expected Output

When run successfully, the application will:
1. Create a 640x480 window titled "SDL3 Tutorial: Textures and Extension Libraries"
2. Display a PNG image centered on a white background
3. Handle window close events to exit gracefully
4. Log initialization and cleanup steps to the console

## Learning Outcomes

After studying this code, you will understand:
- How to transition from surfaces to hardware-accelerated rendering
- How to integrate and use SDL3 extension libraries
- How to create reusable classes for game development
- Proper resource management in SDL3 applications
- The performance benefits of hardware acceleration
- How to load and display various image formats beyond BMP

## Next Steps

This tutorial provides the foundation for:
- Sprite rendering and animation
- Multiple texture management
- Advanced rendering techniques (scaling, rotation, blending)
- Game object systems with texture components

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

This is my personal educational project implementing SDL3 concepts. All code and assets are original or free-licensed. Please refer to SDL3's license
