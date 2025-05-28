# fract_ol

This project aims to graphically explore complex mathematical structures by rendering fractals using the MiniLibX graphical library.

## Project Goals

- Render the Mandelbrot and Julia fractal sets in real time.
- Understand and implement complex number mappings and iterative functions.
- Enable interactive navigation via keyboard and mouse input.

## Features Implemented

- Full rendering of the Mandelbrot set
- Accurate pixel-to-complex-plane mapping
- Smooth zoom using `+` and `-` keys (continuous while held) and mouse wheel scrolling
- Navigation using arrow keys
- X11-based windowing via MiniLibX (Linux only)
- Modular file structure compatible with the 42 Norm
- Functional Makefile with support for Libft and MiniLibX

## Project Structure

```
fract_ol/
├── include/
│   └── fract_ol.h
├── libft/
├── minilibx/
├── src/
│   ├── main.c
│   ├── init_mlx.c
│   ├── mandelbrot.c
│   ├── events.c
│   ├── keys.c
│   └── draw_utils.c
└── README.md
```

## In Progress

- Julia set implementation with dynamic parameters from CLI
- Iteration tuning based on zoom depth
- Improved coloring gradients and style variations

## How to Build

```bash
make fclean && make
```

## How to Run

```bash
./fract_ol mandelbrot
```

For Julia (coming soon):

```bash
./fract_ol julia <real> <imag>
```

## Requirements

- Linux OS with X11 support
- MiniLibX (included)
- Libft (included as submodule/directory)
