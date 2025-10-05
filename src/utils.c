#include "../include/utils.h"
#include "../include/game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

static struct termios old_term, raw;

void debug(Draw ops, Player p) {
  printf("\e[%d;%df\r", ops.term_y, 0);
  printf("%d, %d %c", p.x, p.y, ops.key);
}

void clear_screen() {
  fflush(stdout);
  printf("\033[2J");
}

void reset_terminal() {
  printf("\e[m");    // reset color
  printf("\e[?25h"); // show cursor
  fflush(stdout);
  tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
}

void raw_config() {
  tcgetattr(STDIN_FILENO, &old_term);
  atexit(reset_terminal);
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag |= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

  printf("\e[?25l"); // hide cursor
}

int get_term_size(int *rows, int *cols) {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    return -1;
  } else {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return 0;
  }
}

void error(char *str, int val) {
  reset_terminal();
  printf("\n%s %d\n", str, val);
  exit(0);
}
