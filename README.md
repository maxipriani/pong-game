# Pong 

Implementation of the classic **Pong** game in **C**, using **SDL2**.  

## Features

- **Single Player vs CPU**  
  Basic AI-controlled paddle opponent.  

- **Game Mechanics**  
  Ball physics, paddle movement, and collision detection.  

- **Rendering**  
  Smooth graphics and input handling with SDL2.  

- **Code Structure**  
  Modularized codebase with CMake build system.  

## Prerequisites

- **C Compiler**
- **CMake**  
- **SDL2** and **SDL2_ttf**  

Install the required dependencies using:

```bash
sudo apt update
sudo apt install gcc cmake libsdl2-dev libsdl2-ttf-dev
```

## Build & Run

1. Clone the repository.
2. Create a build directory, compile the project and run the game:

```bash
mkdir build
cd build && cmake ..
make
./pong
```