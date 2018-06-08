#include "InputPane.h"

InputPane::InputPane(int x, int y, int width, int height) : Pane(x, y, width, height){
  mvwprintw(m_pWindow, 0, 3, " < INPUT > ");
}

InputPane::~InputPane(){}

void InputPane::Draw(){
  wattron(m_pWindow, COLOR_PAIR(3));
  mvwprintw(m_pWindow, 1, 2, "Input Position (ex : A3)");
  mvwprintw(m_pWindow, 2, 2, "Input : ");
  wattroff(m_pWindow, COLOR_PAIR(3));
  wrefresh(m_pWindow);
}

Position InputPane::GetInput(){
  char input[3];
  Position p;
  wattron(m_pWindow, COLOR_PAIR(3));
  mvwscanw(m_pWindow, 2, 10, "%s", input);
  mvwprintw(m_pWindow, 2, 10, "    ");
  wattroff(m_pWindow, COLOR_PAIR(3));
  wrefresh(m_pWindow);
  if (input[0] == 'X' || input[0] == 'x') {
    p.x = 100;
    p.y = 100;
    return p;
  }
  input[0] = input[0] - 'A';
  input[1] = input[1] - '0';
  input[1] --;
  p.x = input[0];
  p.y = input[1];
  return p;
}
