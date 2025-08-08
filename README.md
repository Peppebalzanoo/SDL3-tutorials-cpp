# SDL3 Tutorials Collection

## Overview

This repository contains a collection of SDL3 tutorials that serve as my personal learning implementation while studying SDL3 (Simple DirectMedia Layer 3) programming concepts. These tutorials represent my own interpretation and implementation of fundamental SDL3 concepts.

**Note**: This tutorial collection is currently under active development. More tutorials covering advanced SDL3 topics will be added as I continue my learning journey.

## About SDL3

[SDL3](https://github.com/libsdl-org/SDL) is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playbook software, emulators, and popular games including Valve's award-winning catalog.

## Development Environment

This project is developed using:
- **IDE**: Visual Studio Code
- **Operating System**: Windows
- **Compiler**: MinGW-w64 (GCC for Windows)
- **Build System**: Batch scripts for easy compilation

## Repository Structure

This repository is organized with each tutorial in its own directory:

```
SDL3 Project/
├── 01-sdl-basics/                     # Basic SDL3 window creation and BMP loading
├── 02-sdl-textures/                   # Working with textures and SDL3_image
├── 03-sdl-event-handling/             # Keyboard input handling
├── 04-sdl-color-keying/               # Transparency and color keying
├── 05-sdl-clipping-and-stretching/    # Texture clipping and stretching techniques
├── 06-sdl-rotation-and-flipping/      # Texture rotation and flipping transformations
├── assets/                            # Original and free-licensed media files
│   ├── 01hello-world.bmp              # Original bitmap for tutorial 01
│   ├── 02img.png                      # Original texture for tutorial 02
│   ├── 03img.png                      # Original default texture for tutorial 03
│   ├── 03up.png                       # Original directional sprites
│   ├── 03down.png                     
│   ├── 03left.png                     
│   ├── 03right.png                    
│   ├── 04background0.png              # Original background image
│   ├── 04background1.png              # Original background layer 1
│   ├── 04sprite.png                   # Original sprite with transparency
│   ├── 05dots.png                     # Original sprite sheet for clipping tutorial
│   └── 06arrow.png                    # Original arrow sprite for rotation and flipping
├── lib/                               # SDL3 and SDL3_image libraries
│   ├── SDL3-3.2.18/                   # SDL3 development libraries
│   └── SDL3_image-3.2.4/              # SDL3_image extension libraries
├── .gitignore                         # Git ignore file
└── README.md                          # This file
```

## Tutorial Contents

### Tutorial 01: SDL Basics ✅
- Basic SDL3 initialization
- Window creation and management
- Loading and displaying BMP images
- Basic event handling
- Resource cleanup

### Tutorial 02: SDL Textures ✅
- Introduction to [SDL3_image](https://github.com/libsdl-org/SDL_image)
- Loading PNG images
- Working with textures vs surfaces
- Renderer-based graphics

### Tutorial 03: SDL Event Handling ✅
- Keyboard event handling
- Dynamic texture loading based on input
- Custom texture wrapper class
- Event-driven programming concepts

### Tutorial 04: SDL Color Keying ✅
- Transparency implementation
- Color keying techniques
- Layered rendering
- Sprite composition

### Tutorial 05: SDL Clipping and Stretching ✅
- Texture clipping using SDL_FRect
- Sprite sheet extraction
- Texture stretching and scaling
- Multiple rendering modes

### Tutorial 06: SDL Rotation and Flipping ✅
- Texture rotation using degrees
- Horizontal and vertical flipping
- Center-based transformations
- Interactive transformation controls

### More Tutorials Coming Soon... 🚧
This collection is actively being expanded with additional SDL3 topics including:
- Audio and sound effects
- Mouse input handling
- Animation systems
- Advanced rendering techniques
- Game physics basics
- And much more!

## Prerequisites

To build and run these tutorials, you'll need:

- **Operating System**: Windows
- **IDE**: Visual Studio Code (recommended)
- **C++ Compiler**: MinGW-w64 (GCC for Windows)
- **SDL3 Development Libraries**: Download from [SDL3 Releases](https://github.com/libsdl-org/SDL/releases) and place in `lib/SDL3-3.2.18/`
- **SDL3_image Extension**: Download from [SDL3_image Releases](https://github.com/libsdl-org/SDL_image/releases) and place in `lib/SDL3_image-3.2.4/` for PNG/JPG support

### Setting Up SDL3 Libraries

1. **Download SDL3 Development Libraries**:
   - Visit [SDL3 Releases](https://github.com/libsdl-org/SDL/releases)
   - Download the MinGW development libraries for Windows
   - Extract to `lib/SDL3-3.2.18/`

2. **Download SDL3_image Extension**:
   - Visit [SDL3_image Releases](https://github.com/libsdl-org/SDL_image/releases)
   - Download the MinGW development libraries for Windows
   - Extract to `lib/SDL3_image-3.2.4/`

### Setting Up MinGW-w64
If you don't have MinGW-w64 installed:
1. Download from [MinGW-w64](https://www.mingw-w64.org/downloads/)
2. Add the `bin` directory to your system PATH
3. Verify installation: `g++ --version`

## Building the Tutorials

Each tutorial directory contains a `build.bat` script optimized for MinGW-w64:

```bash
cd 01-sdl-basics
./build.bat
```

Or compile manually using MinGW-w64:
```bash
g++ -std=c++17 -I../lib/SDL3-3.2.18/x86_64-w64-mingw32/include -L../lib/SDL3-3.2.18/x86_64-w64-mingw32/lib -o main 01-main.cpp -lSDL3 -lSDL3_image
```

## Learning Path

These tutorials are designed to be completed in order:

1. **Start with Tutorial 01** to understand basic SDL3 concepts
2. **Progress through Tutorial 02** to learn about textures and extensions
3. **Continue with Tutorial 03** for input handling
4. **Complete Tutorial 04** for advanced graphics techniques
5. **Continue with Tutorial 05** for sprite sheet manipulation and scaling
6. **Finish with Tutorial 06** for texture transformations and visual effects

Each tutorial builds upon concepts from previous ones, creating a solid foundation for SDL3 development.

**Stay tuned for more tutorials as this collection continues to grow!**

## Assets and Resources

The `assets/` directory contains original and free-licensed media files created specifically for this project:
- `01hello-world.bmp` - Original bitmap image for tutorial 01 basic loading
- `02img.png` - Original texture for tutorial 02 rendering examples
- `03img.png` - Original default texture for tutorial 03
- `03up.png`, `03down.png`, `03left.png`, `03right.png` - Original directional arrow sprites for keyboard input
- `04background0.png` - Original background layer 0 for tutorial 04
- `04background1.png` - Original background layer 1 for tutorial 04
- `04sprite.png` - Original sprite with transparent areas for color keying tutorial
- `05dots.png` - Original sprite sheet with multiple colored dots for clipping tutorial
- `06arrow.png` - Original arrow sprite with white background for rotation and flipping tutorial

**All graphical assets in this project are either original creations or sourced from free-licensed resources. No copyrighted material from external tutorials has been included.**

## Getting Started

1. **Clone this repository**
2. **Download and setup SDL3 libraries** (see Prerequisites section)
3. **Open in Visual Studio Code**: `code .`
4. **Ensure MinGW-w64 is installed** and in your PATH
5. **Navigate to the first tutorial**: `cd 01-sdl-basics`
6. **Read the tutorial README**: Each directory contains detailed explanations
7. **Build and run**: Use the provided build scripts
8. **Experiment**: Modify the code to understand the concepts better

## Additional Resources

- **Official SDL3 Documentation**: [SDL3 Wiki](https://wiki.libsdl.org/SDL3/)
- **SDL3 GitHub Repository**: [libsdl-org/SDL](https://github.com/libsdl-org/SDL)
- **SDL3_image GitHub Repository**: [libsdl-org/SDL_image](https://github.com/libsdl-org/SDL_image)
- **SDL3 Release Downloads**: [SDL3 Releases](https://github.com/libsdl-org/SDL/releases)
- **SDL3_image Release Downloads**: [SDL3_image Releases](https://github.com/libsdl-org/SDL_image/releases)
- **MinGW-w64**: [Official Website](https://www.mingw-w64.org/)
- **Visual Studio Code**: [C++ Development Guide](https://code.visualstudio.com/docs/languages/cpp)

## Contributing

This repository represents my personal learning journey with SDL3 in a Windows + Visual Studio Code environment. If you find this helpful for your own learning:
1. Feel free to use it as a reference for your own implementations
2. All code and assets are provided as educational examples
3. Consider creating your own interpretations of the concepts

## Third-Party Licenses

[SDL3](https://github.com/libsdl-org/SDL) and [SDL3_image](https://github.com/libsdl-org/SDL_image) are © the SDL development team and licensed under the zlib license.

**Note**: SDL3 libraries are not included in this repository due to their size. You need to download them separately from the official releases:
- **SDL3**: [Download from SDL3 Releases](https://github.com/libsdl-org/SDL/releases)
- **SDL3_image**: [Download from SDL3_image Releases](https://github.com/libsdl-org/SDL_image/releases)

These libraries are provided for educational and development purposes only. This repository does not claim ownership of SDL3 or SDL3_image.

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
