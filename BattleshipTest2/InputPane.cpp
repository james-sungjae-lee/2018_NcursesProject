#include "InputPane.hpp"

InputPane::InputPane(int x, int y, int width, int height) : Pane(x, y, width, height){
  mvwprintw(m_pWindow, 0, 3, " < INPUT > ");
}

InputPane::~InputPane(){
}

void InputPane::Draw(){
  wattron(m_pWindow, COLOR_PAIR(3));
  mvwprintw(m_pWindow, 1, 2, "Input(ex: A3) Quit(X or x)");
  mvwprintw(m_pWindow, 2, 2, "Input : ");
  wattroff(m_pWindow, COLOR_PAIR(3));

  wrefresh(m_pWindow);
}

string InputPane::GetInput(){
  char input[3];
  wattron(m_pWindow, COLOR_PAIR(3));
  mvwscanw(m_pWindow, 2, 10, "%s", input);
  mvwprintw(m_pWindow, 2, 10, "    ");
  wattroff(m_pWindow, COLOR_PAIR(3));
  wrefresh(m_pWindow);
  input[1] --;
  return input;
}
