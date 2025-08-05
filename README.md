# SDL3 Tutorials Collection

## Overview

This repository contains a collection of SDL3 tutorials based on the excellent work by **Lazy Foo' Productions**. These tutorials provide a comprehensive introduction to SDL3 (Simple DirectMedia Layer 3) programming in C++.

## Original Source

The tutorials are adapted from the official SDL3 tutorial series by Lazy Foo' Productions:
- **Website**: [https://lazyfoo.net/tutorials/SDL3/index.php](https://lazyfoo.net/tutorials/SDL3/index.php)
- **Copyright**: Lazy Foo' Productions 2004-2025

## About SDL3

SDL3 is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and popular games including Valve's award-winning catalog.

## Repository Structure

This repository is organized with each tutorial in its own directory:

```
SDL3 Project/
├── 01-hello-sdl3/                     # Basic SDL3 window creation and BMP loading
├── 02-textures-and-extension-libraries/ # Working with textures and SDL3_image
├── 03-key-presses-and-key-states/     # Keyboard input handling
├── 04-color-keying/                   # Transparency and color keying
├── assets/                            # Shared image and media files
├── lib/                               # SDL3 and SDL3_image libraries
└── README.md                          # This file
```

## Tutorial Contents

### Tutorial 01: Hello SDL3
- Basic SDL3 initialization
- Window creation and management
- Loading and displaying BMP images
- Basic event handling
- Resource cleanup

### Tutorial 02: Textures and Extension Libraries
- Introduction to SDL3_image
- Loading PNG images
- Working with textures vs surfaces
- Renderer-based graphics

### Tutorial 03: Key Presses and Key States
- Keyboard event handling
- Dynamic texture loading based on input
- Custom texture wrapper class
- Event-driven programming concepts

### Tutorial 04: Color Keying
- Transparency implementation
- Color keying techniques
- Layered rendering
- Sprite composition

## Prerequisites

To build and run these tutorials, you'll need:

- **C++ Compiler**: MinGW-w64, Visual Studio, or similar
- **SDL3 Development Libraries**: Included in the `lib/` directory
- **SDL3_image Extension**: For PNG/JPG support
- **Windows OS**: Current setup is configured for Windows

## Building the Tutorials

Each tutorial directory contains a `build.bat` script for easy compilation:

```bash
cd 01-hello-sdl3
./build.bat
```

Or compile manually:
```bash
g++ -I../lib/SDL3-3.2.18/x86_64-w64-mingw32/include -L../lib/SDL3-3.2.18/x86_64-w64-mingw32/lib -o main 01-main.cpp -lSDL3 -lSDL3_image
```

## Learning Path

These tutorials are designed to be completed in order:

1. **Start with Tutorial 01** to understand basic SDL3 concepts
2. **Progress through Tutorial 02** to learn about textures and extensions
3. **Continue with Tutorial 03** for input handling
4. **Complete Tutorial 04** for advanced graphics techniques

Each tutorial builds upon concepts from previous ones, creating a solid foundation for SDL3 development.

## Assets and Resources

The `assets/` directory contains shared media files used across tutorials:
- `hello-sdl3.bmp` - Basic bitmap image
- `loaded.png` - Default texture
- `up.png`, `down.png`, `left.png`, `right.png` - Directional sprites
- `background.png` - Background image for layering
- `foo.png` - Sprite with transparent areas

## License and Attribution

This tutorial collection is based on the work of **Lazy Foo' Productions**. The original tutorials are copyrighted material and this repository serves as a learning implementation following their educational content.

- **Original Tutorials**: © Lazy Foo' Productions 2004-2025
- **Implementation**: Educational use following tutorial guidelines

## Getting Started

1. **Clone this repository**
2. **Navigate to the first tutorial**: `cd 01-hello-sdl3`
3. **Read the tutorial README**: Each directory contains detailed explanations
4. **Build and run**: Use the provided build scripts
5. **Experiment**: Modify the code to understand the concepts better

## Additional Resources

- **Official SDL3 Documentation**: [SDL3 Wiki](https://wiki.libsdl.org/SDL3/)
- **Lazy Foo' Productions**: [Original Tutorial Site](https://lazyfoo.net/)
- **SDL3 GitHub**: [SDL3 Source Code](https://github.com/libsdl-org/SDL)

## Contributing

This repository is for educational purposes. If you find issues or improvements:
1. Refer to the original Lazy Foo' tutorials first
2. Test your changes thoroughly
3. Ensure compatibility with the tutorial progression

Happy coding with SDL3! 🎮
