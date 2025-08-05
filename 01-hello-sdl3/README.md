# SDL3 Tutorial: Hello SDL3

A basic SDL3 application that demonstrates fundamental graphics programming concepts including window creation, surface manipulation, image loading, and event handling.

## Overview

This project creates a simple SDL3 application that:
- Initializes SDL3 video subsystem
- Creates a window with OpenGL support
- Loads and displays a BMP image
- Handles user input events (window close)
- Properly cleans up resources

## Features

- **Window Management**: Creates a 640x480 pixel window with OpenGL support
- **Image Loading**: Loads and displays BMP images using SDL3's built-in BMP loader
- **Event Handling**: Responds to quit events (window close button, Alt+F4, etc.)
- **Resource Management**: Proper cleanup of SDL3 resources to prevent memory leaks
- **Error Handling**: Comprehensive error checking with detailed logging

## Requirements

- SDL3 library (version 3.2.18 or compatible)
- C++17 compatible compiler
- Windows (MinGW-w64) - current build configuration

## Project Structure

```
01-hello-sdl3/
├── 01-main.cpp        # Main application source code
├── build.bat          # Build script for Windows
├── hello-sdl3.bmp     # Sample image file
├── main.exe           # Compiled executable
├── SDL3.dll           # SDL3 runtime library
└── README.md          # This file
```

## Building

Run the build script:
```bash
build.bat
```

Or compile manually:
```bash
g++ -std=c++17 01-main.cpp -I../lib/SDL3-3.2.18/x86_64-w64-mingw32/include -L../lib/SDL3-3.2.18/x86_64-w64-mingw32/lib -lSDL3 -o main.exe
```

## Running

1. Ensure `SDL3.dll` is in the same directory as the executable
2. Place your BMP image at `../assets/hello-sdl3.bmp` (relative to executable)
3. Run the executable:
   ```bash
   ./main.exe
   ```

## Code Structure

### Functions

- **`init()`**: Initializes SDL3, creates window, and obtains the window surface
- **`loadMedia()`**: Loads BMP images from the assets directory
- **`cleanup()`**: Properly frees all SDL3 resources and resets pointers
- **`main()`**: Main application loop handling events and rendering

### Main Loop

The application follows the standard game/graphics programming pattern:

1. **Initialization**: Set up SDL3 and create window
2. **Asset Loading**: Load required images and resources
3. **Main Loop**:
   - Handle input events
   - Clear screen (fill with white)
   - Render image to screen
   - Update display
4. **Cleanup**: Free all resources

### Event Handling

Currently handles:
- `SDL_EVENT_QUIT`: Window close events

### Error Handling

- All SDL3 function calls are checked for errors
- Detailed error messages logged using SDL3's logging system
- Graceful failure with appropriate exit codes

## Exit Codes

- `0`: Success
- `1`: SDL3 initialization failed
- `2`: Media loading failed

## Constants

- `SCREEN_WIDTH`: 640 pixels
- `SCREEN_HEIGHT`: 480 pixels
- `WINDOW_TITLE`: "SDL3 Tutorial: Hello SDL3"

## Learning Objectives

This tutorial demonstrates:

1. **SDL3 Initialization**: How to properly initialize SDL3 subsystems
2. **Window Creation**: Creating a window with specific properties
3. **Surface Operations**: Working with SDL3 surfaces for 2D graphics
4. **Image Loading**: Loading and displaying bitmap images
5. **Event Loop**: Implementing a proper event-driven main loop
6. **Resource Management**: Proper cleanup to prevent memory leaks
7. **Error Handling**: Robust error checking and logging

## Next Steps

This basic example can be extended to include:
- Loading different image formats (PNG, JPG) using SDL3_image
- Keyboard and mouse input handling
- Animation and sprite management
- Audio playback
- More complex graphics operations

## Dependencies

- SDL3 (Simple DirectMedia Layer 3)
- Standard C++ library

## License

This is a tutorial/educational project. Please refer to SDL3's license for library usage terms.
