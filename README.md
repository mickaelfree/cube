*This project has been created as part of the 42 curriculum by mickmart, akarapkh.*

# cub3D

## Description

cub3D is a 3D graphical engine inspired by the iconic Wolfenstein 3D (1992), the first true First Person Shooter. The project uses ray-casting to render a first-person perspective view inside a maze, built with the miniLibX graphics library.

The engine reads a `.cub` scene file that defines wall textures (North, South, East, West), floor and ceiling colors, and the map layout. It then renders the maze in real time, allowing the player to navigate through it.

### Features

**Mandatory:**
- Ray-casting based 3D rendering
- Textured walls with orientation-based textures (N/S/E/W)
- Configurable floor and ceiling colors
- Smooth player movement (W/A/S/D) and rotation (arrow keys)
- `.cub` scene file parsing with error handling
- FPS counter
- Precomputed trigonometric tables for performance

**Bonus:**
- Wall collisions
- Minimap system
- Mouse rotation (toggle with K)

## Instructions

### Prerequisites

- Linux (X11)
- `cc` compiler
- `make`
- X11 development libraries (`libx11-dev`, `libxext-dev`)

### Compilation

```bash
# Build mandatory version
make

# Build bonus version
make bonus

# Clean object files
make clean

# Full clean (objects + binaries)
make fclean

# Rebuild
make re
```

### Execution

```bash
./cub3D map.cub
```

The program takes a `.cub` file as argument. The scene file must contain:
- 4 wall textures (NO, SO, WE, EA) with paths to `.xpm` files
- Floor (F) and ceiling (C) colors as R,G,B values (0-255)
- A valid map made of `0` (empty), `1` (wall), and one player spawn (`N`/`S`/`E`/`W`)

Example `.cub` file:
```
NO ./assets/north.xpm
SO ./assets/south.xpm
WE ./assets/west.xpm
EA ./assets/east.xpm

F 100,100,100
C 50,50,220

111111
100101
101001
1100N1
111111
```

### Controls

| Key | Action |
|-----|--------|
| W / A / S / D | Move forward / left / backward / right |
| Left / Right arrow | Rotate view |
| M | Toggle minimap (bonus) |
| K | Toggle mouse rotation (bonus) |
| ESC | Quit |

## Resources

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Reference tutorial for understanding the DDA ray-casting algorithm
- [miniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Documentation for the graphics library used
- [Wolfenstein 3D - Game Engine Black Book](https://fabiensanglard.net/gebbwolf3d/) - In-depth analysis of the original Wolfenstein 3D engine by Fabien Sanglard

### AI usage

AI tools were used during development to assist with:
- Generating documentation (this README)
- Help to make roadmap and planification


All AI-generated suggestions were reviewed, understood, and adapted before being integrated into the project.
