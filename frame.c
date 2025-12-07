#include "frame.h"


void frame_init(frame_t *frame, frame_data data){
    frame = (frame_t *)malloc(sizeof(frame_t));
    frame->SDL_rect.x = data.sprite_x;
    frame->SDL_rect.y = data.sprite_y;
    frame->SDL_rect.h = data.sprite_height;
    frame->SDL_rect.w = data.sprite_width;

    frame->pos_relative_x = data.entity_relative_x;
    frame->pos_relative_y = data.entity_relative_y;
}
void frame_destroy(frame_t **frame){
    free(*frame);
}
void frame_draw(frame_t *fame){
    printf("dibujando frame");
}