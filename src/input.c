#include "../include/input.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <unistd.h>

void input(Draw *ops) {
  char c = get_key();
  switch (c) {
  case 'q':
    system("clear");
    reset_terminal();
    exit(0);
  }
  ops->key = c;
}

char get_key() {
  char c = '\0'; //null char
  read(STDIN_FILENO, &c, 1);
  return c;
}
