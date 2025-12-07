/* Ejemplo de juego principal */
#include "engine\engine.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    
    engine_t engine;
    entity_t *entity;
    animation_t *animation;

    engine_init(&engine);

    /* Armamos el personaje */
    printf("creamos una entidad\n");
    engine_create_scene(&engine);
    printf("creamos una entidad 2\n");
    entity = engine_create_entity(&engine,0,0,"image\\esfera.png");
    printf("creamos una entidad 3\n");
    
    /* Animación movimiento hacia la derecha*/
    printf("Creamos animación derecha\n");
    animation_init(animation,true);
    printf("Creamos animación derecha 2\n");
    animation_add_frame(animation,0,0,20,20,5,5);
    printf("Creamos animación derecha 3\n");
    animation_add_frame(animation,21,0,20,20,5,5);
    animation_add_frame(animation,31,0,20,20,5,5);
    animation_add_frame(animation,41,0,20,20,5,5);
    printf("Creamos animación derecha 4\n");
    entity_add_animation(entity,animation);
    printf("Creamos animación derecha 5\n");

    /* Animación movimiento hacia la izquierda*/
    animation_init(animation,true);
    animation_add_frame(animation,0,21,20,20,5,5);
    animation_add_frame(animation,21,21,20,20,5,5);
    animation_add_frame(animation,31,21,20,20,5,5);
    animation_add_frame(animation,41,21,20,20,5,5);
    entity_add_animation(entity,animation);

    /* Animación movimiento hacia arriba*/
    animation_init(animation,true);
    animation_add_frame(animation,0,41,20,20,5,5);
    animation_add_frame(animation,21,41,20,20,5,5);
    animation_add_frame(animation,31,41,20,20,5,5);
    animation_add_frame(animation,41,41,20,20,5,5);
    entity_add_animation(entity,animation);

    /* Animación movimiento hacia abajo*/
    animation_init(animation,true);
    animation_add_frame(animation,0,61,20,20,5,5);
    animation_add_frame(animation,21,61,20,20,5,5);
    animation_add_frame(animation,31,61,20,20,5,5);
    animation_add_frame(animation,41,61,20,20,5,5);
    entity_add_animation(entity,animation);

    printf("Iniciando loop\n");
    engine_loop_start(&engine);
    engine_destroy(&engine);
  
    return 0;
}