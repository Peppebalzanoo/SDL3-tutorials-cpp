# SDL3 Tutorial 03: SDL Event Handling

## Overview

This tutorial demonstrates how to handle keyboard input in SDL3 using key press events. The program creates a window that displays different textures based on which arrow key is pressed by the user.

## What This Program Does

1. **Window Creation**: Creates a 640x480 SDL3 window with a renderer
2. **Texture Management**: Uses a custom `MTexture` class to load and display PNG images
3. **Keyboard Input**: Responds to arrow key presses (UP, DOWN, LEFT, RIGHT)
4. **Dynamic Texture Loading**: Changes the displayed image based on the key pressed
5. **Event Handling**: Processes SDL events in a main loop until the user closes the window

## Key Features

### Custom MTexture Class
- Encapsulates SDL texture functionality
- Handles texture loading from PNG files using SDL3_image
- Provides methods for rendering textures at specific positions
- Manages texture memory automatically

### Keyboard Event Handling
The program responds to the following keys:
- **UP Arrow**: Displays `03up.png`
- **DOWN Arrow**: Displays `03down.png` 
- **LEFT Arrow**: Displays `03left.png`
- **RIGHT Arrow**: Displays `03right.png`

### Default State
- Shows `03img.png` when the program starts
- Centers all textures on the screen
- Uses a white background

## File Structure

```
03-sdl-event-handling/
├── 03-main.cpp          # Main program file
├── MTexture.hpp         # Custom texture class header
├── MTexture.cpp         # Custom texture class implementation
├── build.bat            # Build script
└── README.md            # This file

../                      # Parent directory contains:
├── main.exe             # Compiled executable (shared across tutorials)
├── SDL3.dll             # SDL3 runtime library
└── SDL3_image.dll       # SDL3_image runtime library
```

## Required Assets

The program expects the following original image files in the `../assets/` directory:
- `03img.png` - Default texture shown at startup
- `03up.png` - Texture shown when UP arrow is pressed
- `03down.png` - Texture shown when DOWN arrow is pressed
- `03left.png` - Texture shown when LEFT arrow is pressed
- `03right.png` - Texture shown when RIGHT arrow is pressed

## Key Code Concepts

### Event Handling
```cpp
while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
        quit = true;
    }
    else if (event.type == SDL_EVENT_KEY_DOWN) {
        // Handle key press events
    }
}
```

### Dynamic Texture Loading
The `loadMedia()` function dynamically loads different textures based on the key pressed:
```cpp
bool loadMedia(MTexture &texture, SDL_Renderer *&pRenderer, SDL_Keycode &key_code)
```

### Rendering Pipeline
1. Clear the renderer with white background
2. Render the current texture at the center of the screen
3. Present the rendered content to the window

## Learning Objectives

- Understanding SDL3 event handling system
- Working with keyboard input events
- Dynamic resource loading based on user input
- Custom class design for texture management
- Proper resource cleanup and memory management

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
    -o ../main.exe 03-main.cpp MTexture.cpp \
    -lSDL3 -lSDL3_image
```

### Running
```bash
cd ..
./main.exe
```

## Expected Behavior

When run successfully, the application will:
1. Create a 640x480 window titled "SDL3 Tutorial: Key Presses and Key States"
2. Display the default texture (`03img.png`) centered on a white background
3. Change the displayed image when arrow keys are pressed:
   - UP arrow → `03up.png`
   - DOWN arrow → `03down.png`
   - LEFT arrow → `03left.png`
   - RIGHT arrow → `03right.png`
4. Handle window close events to exit gracefully

## Next Steps

This tutorial builds upon basic SDL3 concepts and introduces:
- Event-driven programming
- User input handling
- Dynamic content switching
- Object-oriented design with custom classes

The next tutorial might cover more advanced input handling, animation, or game loop concepts.

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

This is my personal educational project implementing SDL3 concepts. All code and assets are original or free-licensed. Please refer to SDL3's license for usage rights.
