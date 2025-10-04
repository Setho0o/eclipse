#include <stdio.h>
#include <stdbool.h>
#include "../include/utils.h"
#include "../include/draw.h"

void draw_pos(Draw ops, int x, int y, char val) {
  out_of_bounds(ops,x,y);
  printf("\e[%d;%df%c",y+1,x,val);
}

void out_of_bounds(Draw ops, int x, int y) {
  if (x > ops.term_x) {
    error("error out of bounds x:",x); 
  } else if (y > ops.term_y) {
    error("error out of bounds y:",y); 
  }
}
