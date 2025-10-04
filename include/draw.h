#ifndef _draw_h
#define _draw_h

typedef struct DrawOps {
  int term_x;
  int term_y;
  int cursor_x;
  int cursor_y;
} Draw;

void draw_pos(Draw ops, int x, int y, char val);
void out_of_bounds(Draw ops, int x, int y);

#endif 
