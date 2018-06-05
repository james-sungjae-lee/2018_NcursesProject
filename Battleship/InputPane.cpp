#include "InputPane.hpp"

InputPane::InputPane(int x, int y, int width, int height) : Pane(x, y, width, height){
  mvwprintw(m_pWindow, 0, 3, " < INPUT > ");
}

InputPane::~InputPane(){
}

void InputPane::Draw(){
  wattron(m_pWindow, COLOR_PAIR(3));
  mvwprintw(m_pWindow, 1, 2, "Input position .. (ex A 3)");
  mvwprintw(m_pWindow, 2, 2, "Input : ");
  wattroff(m_pWindow, COLOR_PAIR(3));

  wrefresh(m_pWindow);
}

string InputPane::GetInput(){
  char input[3];
  wattron(m_pWindow, COLOR_PAIR(3));
  mvwscanw(m_pWindow, 2, 10, "%s", input);
  mvwprintw(m_pWindow, 2, 13, "echo:");
  mvwprintw(m_pWindow, 2, 18, "%s", input);
  wattroff(m_pWindow, COLOR_PAIR(3));
  wrefresh(m_pWindow);
  return input;
}

// Position InputPane::GetInput(){
//   char input[3] = {NULL};
//   Position inputPosition;
//
//   wattron(m_pWindow, COLOR_PAIR(3));
//   mvwscanw(m_pWindow, 2, 10, "%s", input);
//   wattroff(m_pWindow, COLOR_PAIR(3));
//   wrefresh(m_pWindow);
//
//   inputPosition.x = input[0] - 'A';
//   inputPosition.y = input[1] - '0';
//
//   return inputPosition;
// }
