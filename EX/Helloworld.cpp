#include <ncurses.h>
int main()
{
  initscr(); // Curses
  start_color(); // Color
  init_pair(1, COLOR_RED,COLOR_WHITE);
  //
  attron(COLOR_PAIR(1)); // Attribute
  printw("Hello world"); // Hello world
  attroff(COLOR_PAIR(1)); // Attribute
  refresh(); //

  getch(); //
  endwin(); // Curses
return 0;
}
