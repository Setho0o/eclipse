#include <stdbool.h>

#include "include/draw.h"
#include "include/input.h"
#include "include/utils.h"


int main() {
  int row, col;
  get_term_size(&row, &col);
  raw_config();

  Draw ops = {.term_x = col, .term_y = row, .cursor_x = 0, .cursor_y = 0};

  while (true) {
    input();

    draw_pos(ops, 0, 0, 'x');
    draw_pos(ops, 0, ops.term_y, 'x');
    draw_pos(ops, ops.term_x, 0, 'x');
    draw_pos(ops, 0, ops.term_y, 'x');
    draw_pos(ops, ops.term_x, ops.term_y, 'x');
 
    clear_screen();
  }
}
