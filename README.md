# SDL3 Tutorials Collection

## Overview

This repository contains a collection of SDL3 tutorials that serve as my personal learning implementation while studying SDL3 (Simple DirectMedia Layer 3) programming concepts. These tutorials represent my own interpretation and implementation of fundamental SDL3 concepts.

## About SDL3

SDL3 is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playbook software, emulators, and popular games including Valve's award-winning catalog.

## Repository Structure

This repository is organized with each tutorial in its own directory:

```
SDL3 Project/
├── 01-sdl-basics/                     # Basic SDL3 window creation and BMP loading
├── 02-sdl-textures/                   # Working with textures and SDL3_image
├── 03-sdl-event-handling/             # Keyboard input handling
├── 04-sdl-color-keying/               # Transparency and color keying
├── assets/                            # Original and free-licensed media files
│   ├── 01hello-world.bmp              # Original bitmap for tutorial 01
│   ├── 02img.png                      # Original texture for tutorial 02
│   ├── 03img.png                      # Original default texture for tutorial 03
│   ├── 03up.png                       # Original directional sprites
│   ├── 03down.png                     
│   ├── 03left.png                     
│   ├── 03right.png                    
│   ├── 04background0.png              # Original background image
│   └── 04sprite.png                   # Original sprite with transparency
├── lib/                               # SDL3 and SDL3_image libraries
│   ├── SDL3-3.2.18/                   # SDL3 development libraries
│   └── SDL3_image-3.2.4/              # SDL3_image extension libraries
├── .gitignore                         # Git ignore file
└── README.md                          # This file
```

## Tutorial Contents

### Tutorial 01: SDL Basics
- Basic SDL3 initialization
- Window creation and management
- Loading and displaying BMP images
- Basic event handling
- Resource cleanup

### Tutorial 02: SDL Textures
- Introduction to SDL3_image
- Loading PNG images
- Working with textures vs surfaces
- Renderer-based graphics

### Tutorial 03: SDL Event Handling
- Keyboard event handling
- Dynamic texture loading based on input
- Custom texture wrapper class
- Event-driven programming concepts

### Tutorial 04: SDL Color Keying
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
cd 01-sdl-basics
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

The `assets/` directory contains original and free-licensed media files created specifically for this project:
- `01hello-world.bmp` - Original bitmap image for tutorial 01 basic loading
- `02img.png` - Original texture for tutorial 02 rendering examples
- `03img.png` - Original default texture for tutorial 03
- `03up.png`, `03down.png`, `03left.png`, `03right.png` - Original directional arrow sprites for keyboard input
- `04background0.png` - Original background layer 0 for tutorial 04
- `04sprite.png` - Original sprite with transparent areas for color keying tutorial

**All graphical assets in this project are either original creations or sourced from free-licensed resources. No copyrighted material from external tutorials has been included.**


## Getting Started

1. **Clone this repository**
2. **Navigate to the first tutorial**: `cd 01-sdl-basics`
3. **Read the tutorial README**: Each directory contains detailed explanations
4. **Build and run**: Use the provided build scripts
5. **Experiment**: Modify the code to understand the concepts better

## Additional Resources

- **Official SDL3 Documentation**: [SDL3 Wiki](https://wiki.libsdl.org/SDL3/)
- **SDL3 GitHub**: [SDL3 Source Code](https://github.com/libsdl-org/SDL)

## Contributing

This repository represents my personal learning journey with SDL3. If you find this helpful for your own learning:
1. Feel free to use it as a reference for your own implementations
2. All code and assets are provided as educational examples
3. Consider creating your own interpretations of the concepts


## License Notice for SDL3

SDL3 and SDL3_image are © the SDL development team and licensed under the zlib license.  
These libraries are included in the `lib/` directory for development convenience.  
A copy of the license is provided in the `COPYING.txt` file as required.

## Learning Reference

While learning SDL3, I referenced the educational content structure from Lazy Foo' Productions to understand core concepts:
- **Reference Website**: [https://lazyfoo.net/tutorials/SDL3/index.php](https://lazyfoo.net/tutorials/SDL3/index.php)

**Important Note**: This repository contains my own original code implementation and interpretation of SDL3 concepts. No source code, assets, or copyrighted material from Lazy Foo' Productions has been redistributed or included in this project.

## License and Attribution

This project represents my personal learning implementation of SDL3 concepts:

- **Implementation**: Original code and interpretation by Giuseppe
- **Assets**: Original creations and free-licensed resources
- **Learning Reference**: Concepts studied from various SDL3 educational resources

**No copyrighted material, source code, or assets from Lazy Foo' Productions or other tutorial sources have been redistributed in this repository.**

Happy coding with SDL3! 🎮
