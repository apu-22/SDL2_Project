#include <iostream>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 820
#define SCREEN_HEIGHT 620
double Radius = 0;

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

void updating_radious()
{
    Radius += 2;
    if (Radius >= SCREEN_HEIGHT / 2)
        Radius = 0;
}

int main(int argc, char *argv[])
{

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

    SDL_Renderer *render = nullptr;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << "Error: Failed to create renderer: " << "SDL_GetError()";
    }

    bool gameIsRunning = true;
    while (gameIsRunning)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameIsRunning = false;
        }

        SDL_SetRenderDrawColor(renderer, 230, 230, 250, 255);

        SDL_RenderClear(renderer);

        updating_radious();

        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

        draw_Circle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Radius);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    SDL_DestroyRenderer(render);

    SDL_Quit();

    return 0;
}