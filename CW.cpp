#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{

    // create a window
    SDL_Window *window = nullptr;

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
        820,
        420,
        SDL_WINDOW_OPENGL);

// Create an SDL renderer for rendering graphics in the window
    SDL_Renderer *renderer = NULL;

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

         SDL_SetRenderDrawColor(renderer, 205, 20, 205, 255);

        // Clear the renderer with the specified draw color
        SDL_RenderClear(renderer);

        // Present the renderer (draw the frame to the window)
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}