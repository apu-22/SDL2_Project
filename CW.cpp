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

    SDL_Delay(5000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}