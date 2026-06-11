# Image Viewer

A simple SDL2 based image viewer for PPM images.

## Description
This program reads a PPM (P6) image from standard input and displays it in a window using SDL2. It demonstrates basic SDL2 window creation, surface manipulation, and event handling.

## Build Instructions

```bash
gcc ImageViewer.c -o ImageViewer $(sdl2-config --cflags --libs)
```

## Run Instructions

```bash
cat image.ppm | ./ImageViewer
```

![Demo Output](/home/sr/IV/demo_output.png)

The program expects a PPM image on stdin. It will open a window displaying the image. Close the window to exit the program.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.
