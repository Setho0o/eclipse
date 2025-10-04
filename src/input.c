#include <stdlib.h>
#include <unistd.h>
#include "../include/input.h"
#include "../include/utils.h"

void input() {
  char c = get_key();
  switch (c) {
    case 'q':  reset_terminal(); exit(0);
  }
}

char get_key() {
  char c = '\0';
  read(STDIN_FILENO, &c, 1);
  return c;
}
