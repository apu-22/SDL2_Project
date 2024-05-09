#include <iostream>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 820
#define SCREEN_HEIGHT 620
#define Radius 200

SDL_Renderer *renderer = NULL;

void draw_Circle(int offsetx, int offsety, int radius)
{
    for (int x = -radius; x <= radius; x++)
    {
        for (int y = -radius; y <= radius; y++)
        {
            if (x * x + y * y <= radius * radius)
            {
                SDL_RenderDrawPoint(renderer, offsetx + x, offsety + y);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // create a window
    SDL_Window *window = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << "SDL_GetError()";
    }
    else
    {
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow(
        "C++ SDL2 Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL);

    // create render
    SDL_Renderer *render = nullptr;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << "Error: Failed to create renderer: " << "SDL_GetError()";
    }
    // creat infinity loop
    bool gameIsRunning = true;
    while (gameIsRunning)
    {
        SDL_Event event;
        // start event loop
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameIsRunning = false;
        }

        SDL_SetRenderDrawColor(renderer, 230, 230, 250, 255);

        // Clear the renderer with the specified draw color
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        // Present the renderer (draw the frame to the window)

        draw_Circle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Radius);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    SDL_DestroyRenderer(render);

    SDL_Quit();

    return 0;
}