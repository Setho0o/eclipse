#include <stdbool.h>

#include "include/input.h"
#include "include/game.h"
#include "include/utils.h"


int main() {
  int row, col;
  get_term_size(&row, &col);
  raw_config();

  Draw ops = draw_init(row,col);
  Player p = player_init(ops.term_x/2 - 1, ops.term_y/2 - 1, 'o');
  Entity e[2] = {{21,20,'0'},{91,5,'x'}};

  while (true) {
    input(&ops);
   
    draw_entitys(ops, e, 2);
    player(ops, &p);
    collisions(&p, e, 2);

    debug(ops, p);
    clear_screen();
  }
}
