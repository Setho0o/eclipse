#ifndef _game_h
#define _game_h

typedef struct DrawOps {
  int term_x;
  int term_y;
  char key; // input sets key in draw ops
} Draw;

typedef struct Player {
  int x;
  int y;
  int last_x; // used for collisons
  int last_y;
  char icon;
} Player;

typedef struct Entity {
  int x;
  int y;
  char icon;
} Entity;

Draw draw_init(int row, int col);
void draw_pos(Draw ops, int x, int y, char val);
void draw_entitys(Draw ops, Entity e[], int arr_size);

Player player_init(int x, int y, char icon);
void player(Draw ops, Player *p);
void draw_player(Draw ops, Player *p);

void collisions(Player *p, Entity e[], int arr_size);
void out_of_bounds(Draw ops, int x, int y);

#endif
