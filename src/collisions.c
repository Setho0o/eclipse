#include "../include/game.h"

void collisions(Player *p, Entity e[], int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    if (p->x == e[i].x && p->y == e[i].y) {
      p->x = p->last_x;
      p->y = p->last_y;
    }
  }
}
