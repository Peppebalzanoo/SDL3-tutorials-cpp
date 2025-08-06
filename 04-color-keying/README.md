# SDL3 Tutorial 04: Color Keying

## Learning Reference and Attribution

This tutorial represents my personal implementation and interpretation of SDL3 concepts. While learning SDL3, I referenced educational content from Lazy Foo' Productions to understand core programming concepts, but this project contains:

- **Original Code**: My own implementation and interpretation of SDL3 concepts
- **Original Assets**: All graphical resources are either my original creations or sourced from free-licensed materials
- **No Redistribution**: No source code, assets, or copyrighted material from Lazy Foo' Productions has been included

**All images and resources in this project are original creations or free-licensed materials. No copyrighted images from external tutorials have been used.**

## Overview

This tutorial demonstrates **color keying** (also known as chroma keying) in SDL3. Color keying is a technique that makes specific colors in an image transparent, allowing for layered rendering without visible backgrounds. This is commonly used for sprites and characters in games.

## What This Program Does

1. **Window Creation**: Creates a 640x480 SDL3 window with a renderer
2. **Color Keying Implementation**: Uses cyan (0x00, 0xFF, 0xFF) as the transparent color
3. **Layered Rendering**: Displays a background image with a foreground sprite on top
4. **Transparency Effect**: The cyan background of the sprite becomes transparent, creating a seamless overlay

## Key Features

### Color Keying Technology
- **Transparent Color**: Cyan (RGB: 0, 255, 255) is set as the color key
- **Automatic Processing**: The `MTexture` class automatically applies color keying when loading textures
- **Clean Rendering**: Sprites appear without visible rectangular backgrounds

### Dual Texture System
The program uses two textures:
- **Background Texture** (`background.png`): Rendered at position (0, 0) covering the entire screen
- **Foreground Texture** (`foreground.png`): Rendered at the center of the screen with transparent cyan areas

### Enhanced MTexture Class
The custom `MTexture` class now includes:
- Color key support using `SDL_SetSurfaceColorKey()`
- Automatic transparency handling during texture creation
- Proper resource management for both surface and texture objects

## File Structure

```
04-color-keying/
├── 04-main.cpp          # Main program file
├── MTexture.hpp         # Custom texture class header
├── MTexture.cpp         # Custom texture class implementation (with color keying)
├── build.bat            # Build script
└── README.md            # This file

../                      # Parent directory contains:
├── main.exe             # Compiled executable (shared across tutorials)
├── SDL3.dll             # SDL3 runtime library
└── SDL3_image.dll       # SDL3_image runtime library
```

## Required Assets

The program expects the following original image files in the `../assets/` directory:
- `background.png` - Original background image that fills the entire screen
- `foreground.png` - Original foreground sprite with cyan areas that will become transparent

## Technical Implementation

### Color Key Setting
```cpp
// Set cyan as transparent color
SDL_SetSurfaceColorKey(loaded_surface, true, SDL_MapSurfaceRGB(loaded_surface, 0x00, 0xFF, 0xFF));
```

### Rendering Order
1. **Clear renderer** with white background
2. **Render background** texture at (0, 0)
3. **Render foreground** texture centered on screen
4. **Present** the final composed image

### Event Handling
- The program responds to any key press by reloading and rendering both textures
- Pressing any key triggers the rendering pipeline
- Close button exits the application

## Key Code Concepts

### Color Keying Process
1. **Load Surface**: Image is loaded into an SDL_Surface
2. **Apply Color Key**: Cyan pixels are marked as transparent
3. **Create Texture**: Surface is converted to texture with transparency preserved
4. **Render**: Texture is drawn with transparent areas allowing background to show through

### Layered Rendering
```cpp
// Render background first (bottom layer)
bg_texture.renderTexture(0.0f, 0.0f, pRenderer);

// Render foreground on top (top layer with transparency)
foreground_texture.renderTexture((SCREEN_WIDTH - foreground_texture.getWidth()) / 2, 
                                (SCREEN_HEIGHT - foreground_texture.getHeight()) / 2, pRenderer);
```

## Learning Objectives

- **Color Keying Concepts**: Understanding how transparency works in 2D graphics
- **Sprite Composition**: Learning to layer images for complex scenes
- **SDL Surface Manipulation**: Working with SDL surfaces before texture conversion
- **Resource Management**: Proper handling of surfaces and textures
- **Visual Effects**: Creating professional-looking sprite rendering

## Common Use Cases

Color keying is essential for:
- **Character Sprites**: Removing backgrounds from character images
- **UI Elements**: Creating transparent interface components
- **Particle Effects**: Rendering effects without rectangular boundaries
- **Tile-based Graphics**: Seamless terrain and object placement

## Building and Running

### Prerequisites
- SDL3 development libraries
- SDL3_image extension library
- C++ compiler (MinGW-w64 or Visual Studio)

### Build Instructions
Use the provided `build.bat` script to compile the program:
```bash
./build.bat
```

Or compile manually:
```bash
g++ -I../lib/SDL3-3.2.18/x86_64-w64-mingw32/include \
    -I../lib/SDL3_image-3.2.4/x86_64-w64-mingw32/include \
    -L../lib/SDL3-3.2.18/x86_64-w64-mingw32/lib \
    -L../lib/SDL3_image-3.2.4/x86_64-w64-mingw32/lib \
    -o ../main.exe 04-main.cpp MTexture.cpp \
    -lSDL3 -lSDL3_image
```

### Running
```bash
cd ..
./main.exe
```

## Visual Result

When running this program, you'll see:
1. A background image filling the entire window
2. A sprite centered on screen with transparent cyan areas
3. The background visible through the transparent parts of the sprite
4. A seamless, professional-looking layered composition

## Next Steps

This tutorial introduces fundamental concepts for:
- Sprite-based game development
- Advanced texture manipulation
- Multi-layer rendering systems
- Professional game graphics pipelines

The next tutorial might cover animation, sprite sheets, or more advanced rendering techniques.

## Dependencies

- SDL3 (Simple DirectMedia Layer 3)
- SDL3_image extension library
- Standard C++ library

## License

This is my personal educational project implementing SDL3 concepts. All code and assets are original or free-licensed. Please refer to SDL3's license for library usage terms.
