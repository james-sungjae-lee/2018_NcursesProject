#include <ncurses.h>
int main()
{
  char key;
  char userName[8];
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0);
  noecho();
  printw("User name: ");
  scanw("%s", userName);
  printw("%s\n", userName);
  printw("When you press key, delete window");
  refresh();
  getch();
  clear();
  refresh();
  getch();
  endwin();
  return 0;
}
