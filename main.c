#include <stdio.h>
#include <SDL3/SDL.h>

int main(){

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        printf("SDL Initialization failed: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "My SDL Window",
        800, // Width
        600, // Height,
        0
    );

    if (window == NULL) {
        // Handle window creation error
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        // Render or update game state here
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}