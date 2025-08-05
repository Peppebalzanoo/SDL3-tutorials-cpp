# SDL3 Tutorial 03: Key Presses and Key States

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
- **UP Arrow**: Displays `up.png`
- **DOWN Arrow**: Displays `down.png` 
- **LEFT Arrow**: Displays `left.png`
- **RIGHT Arrow**: Displays `right.png`

### Default State
- Shows `loaded.png` when the program starts
- Centers all textures on the screen
- Uses a white background

## File Structure

```
03-key-presses-and-key-states/
├── 03-main.cpp          # Main program file
├── MTexture.hpp         # Custom texture class header
├── MTexture.cpp         # Custom texture class implementation
├── build.bat            # Build script
└── README.md            # This file
```

## Required Assets

The program expects the following image files in the `../assets/` directory:
- `loaded.png` - Default texture shown at startup
- `up.png` - Texture shown when UP arrow is pressed
- `down.png` - Texture shown when DOWN arrow is pressed
- `left.png` - Texture shown when LEFT arrow is pressed
- `right.png` - Texture shown when RIGHT arrow is pressed

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

Use the provided `build.bat` script to compile the program. Make sure you have:
- SDL3 development libraries
- SDL3_image extension library
- A C++ compiler (like MinGW-w64)

## Next Steps

This tutorial builds upon basic SDL3 concepts and introduces:
- Event-driven programming
- User input handling
- Dynamic content switching
- Object-oriented design with custom classes

The next tutorial might cover more advanced input handling, animation, or game loop concepts.
