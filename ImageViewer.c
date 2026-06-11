#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main()
{
    FILE *f = stdin;

    char *pt = calloc(1000, sizeof(char));
    char *dim = calloc(1000, sizeof(char));

    // Read PPM header lines
    fgets(pt, 1000, f);      // P3 or P6
    fgets(dim, 1000, f);     // width height
    fgets(pt, 1000, f);      // max color value

    int width = 0;
    int height = 0;

    sscanf(dim, "%d %d", &width, &height);
    free(pt);
    free(dim);

    printf("width: %d, height: %d\n", width, height);

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *p = SDL_CreateWindow(
        "Image Viewer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        0
    );

    SDL_Surface *s = SDL_GetWindowSurface(p);

    SDL_Rect pix = {0, 0, 1, 1};
    Uint32 color=0;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            Uint8 r,g,b;
            r=(char) getchar();
            g=(char) getchar();
            b=(char) getchar();
            color = SDL_MapRGB(s->format, r, g, b);
            pix.x = i;
            pix.y = j;
            SDL_FillRect(
                s,
                &pix,
                color
            );
        }
    }

    SDL_UpdateWindowSurface(p);
    int app_is_running = 1;
    while(app_is_running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                app_is_running = 0;
            }
        }
        SDL_Delay(100);
    }

    SDL_DestroyWindow(p);
    SDL_Quit();

    return 0;
}