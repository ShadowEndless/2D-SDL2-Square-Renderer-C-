# SDL2 Square Renderer (C)

A simple 2D rendering project built in C using SDL2. This application renders a moving square on the screen, demonstrating core concepts of real-time rendering, frame control, and low-level graphics handling.

---

## Overview

This project was developed to explore low-level programming concepts such as:

- Real-time rendering using SDL2  
- Frame rate control and delta time calculation  
- Event handling (keyboard and window events)  
- Basic animation and movement logic  
- Memory and resource management in C  

The application displays a red square moving vertically within the screen bounds, using time-based movement to ensure smooth animation across different frame rates.

---

## Features

- Window creation using SDL2  
- Hardware-accelerated rendering  
- Frame rate limiting using `SDL_Delay`  
- Delta time calculation for consistent movement  
- Event-driven input handling (ESC to exit)  
- Boundary collision logic for movement constraints  
- Clean initialization and teardown of SDL resources  

---

## How It Works

The application follows a classic game loop structure:

1. **Process Input** → captures user events  
2. **Update** → updates object position using delta time  
3. **Render** → draws the square on screen  

Movement is calculated using time-based updates:

- Velocity is scaled using `delta_time`  
- Ensures consistent speed regardless of frame rate  
- Prevents frame-dependent inconsistencies  

---

## Technologies Used

- C (low-level systems programming)  
- SDL2 (Simple DirectMedia Layer)  

---

## Build Instructions

### Requirements

- GCC or Clang  
- SDL2 development libraries  

### Build using Makefile

```bash
make
./sdl_app
Manual Build (Linux)
gcc main.c -o sdl_app -lSDL2
./sdl_app
Precompiled Binary (Linux)
```
A precompiled Linux executable is available in the Releases section.

To run:
```Bash
chmod +x sdl_app
./sdl_app
```
---

## Controls
ESC → Exit application
Window close button → Exit application

## Project Structure
. src
├── main.c
├── constants.h
├── function_prototypes.h
├── makefile
└── README.md

---

## Learning Highlights

This project demonstrates:

- Understanding of real-time rendering loops
- Use of delta time for frame-independent animation
- Low-level graphics handling with SDL2
- Manual resource management (initialization and cleanup)
- Basic collision handling within screen bounds
## Future Improvements
-Add horizontal movement and user input controls
-Introduce multiple objects
-Implement basic physics (acceleration, gravity)
-Expand into a simple 2D engine structure
## License

This project is available under the MIT License.

