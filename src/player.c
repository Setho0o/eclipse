#include "../include/game.h"

Player player_init(int x, int y, char icon) {
  Player p = {.x = x, .y = y, .icon = icon};
  return p;
}

void player(Draw ops, Player *p) {
  p->last_x = p->x;
  p->last_y = p->y;
  if (ops.key == 'w') {
    p->y = p->y - 1;
  } else if (ops.key == 'a') {
    p->x = p->x - 2;
  } else if (ops.key == 's') {
    p->y = p->y + 1;
  } else if (ops.key == 'd') {
    p->x = p->x + 2;
  }
  draw_player(ops, p);
}

void draw_player(Draw ops, Player *p) {
  draw_pos(ops, p->x, p->y, p->icon); 
}
