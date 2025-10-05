#include "../include/game.h"
#include "../include/utils.h"
#include <stdbool.h>
#include <stdio.h>

Draw draw_init(int row, int col) {
  Draw ops = {.term_x = col, .term_y = row, .key = '\0'};
  return ops;
}

void draw_pos(Draw ops, int x, int y, char val) {
  out_of_bounds(ops, x, y);
  printf("\e[%d;%df%c\r", y, x, val);
}

void out_of_bounds(Draw ops, int x, int y) {
  if (x > ops.term_x || x < 0) {
    error("error x out of bounds:", x);
  } else if (y > ops.term_y || y < 1) { // y starts at 1 pretty lame
    error("error y out of bounds:", y);
  }
}

void draw_entitys(Draw ops, Entity e[], int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    draw_pos(ops, e[i].x, e[i].y, e[i].icon);
  }
}
