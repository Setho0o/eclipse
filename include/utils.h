#ifndef _utils_h
#define _utils_h
#include "game.h"

void debug(Draw ops, Player p);
void clear_screen();
void reset_terminal();
void raw_config();
int get_term_size(int *row, int *col);
void error(char *str, int val);

#endif
