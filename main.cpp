#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

const int WIDTH = 800, HEIGHT = 600;
const float gravity = 9.8; // Gravitational constant

int mouseX = 0;
int mouseY = 0;

Uint32 previousTime = 0;

int main(int argc, char* argv[]) 
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("PixelPhysics", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == window) 
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;

    while (true) 
    {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - previousTime;
        previousTime = currentTime;

        if (SDL_PollEvent(&windowEvent)) 
        {
            if (SDL_QUIT == windowEvent.type) 
            {
                break;
            }
        }

        SDL_GetMouseState(&mouseX, &mouseY);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return EXIT_SUCCESS;
}
