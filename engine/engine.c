#include "engine.h"
#include <stdbool.h>

bool engine_init(engine_t *e){
    printf("iniciando el engine\n");
    e->scene = NULL;
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    printf("Creando propiedades del window\n");
    e->window_props = SDL_CreateProperties();

    if(e->window_props == 0) {
        SDL_Log("Unable to create properties: %s", SDL_GetError());
        return false;
    }

    SDL_SetNumberProperty(e->window_props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, 640);
    SDL_SetNumberProperty(e->window_props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, 480);

    printf("Creando el window\n");
    e->window = SDL_CreateWindowWithProperties(e->window_props);
    if(e->window == NULL) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 0;
    }
}

void engine_loop_start(engine_t *e){
    bool running = true;
    SDL_Event event;

    while(running){
        /* Captura de eventos */
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false; // Exit loop on close event
            }
        }

        /* Dibujo del frame actual*/
        scene_draw(e->scene,e->renderer);

        SDL_RenderClear(e->renderer);
        SDL_RenderPresent(e->renderer);
    }
}

entity_t *engine_create_entity(engine_t *e, int32_t x, int32_t y, char *file_path_texture){
    entity_t *entity;
    entity_init(entity, x, y, e->renderer, file_path_texture);
    return entity;
}

void engine_create_scene(engine_t *e){
    if(e->scene != NULL)
        scene_destroy(&(e->scene));
    e->scene = (scene_t *)malloc(sizeof(scene_t));
}

void engine_destroy(engine_t *e){
    SDL_DestroyWindow(e->window);
    SDL_DestroyProperties(e->window_props);
}