#include "StatPane.hpp"

StatPane::StatPane(int x, int y, int width, int height) : Pane(x, y, width, height){
  mvwprintw(m_pWindow, 0, 3, " < STATUS > ");
}

void StatPane::Draw(){
  wattron(m_pWindow, COLOR_PAIR(2));
  mvwprintw(m_pWindow, 1, 2, "AIRCRAFT : AAAAA");
  mvwprintw(m_pWindow, 2, 2, "BATTLESHIP : BBBB");
  mvwprintw(m_pWindow, 3, 2, "CRUISER : CCC");
  mvwprintw(m_pWindow, 4, 2, "DESTROYER : DD DD");
  wattroff(m_pWindow, COLOR_PAIR(2));

  wrefresh(m_pWindow);
}

StatPane::~StatPane(){
}

void StatPane::DrawTurn(int turn){
  wattron(m_pWindow, COLOR_PAIR(2));
  mvwprintw(m_pWindow, 5, 2, "Turn : ");
  mvwprintw(m_pWindow, 5, 10, "%d", turn);
  wattroff(m_pWindow, COLOR_PAIR(2));

  wrefresh(m_pWindow);
}

void StatPane::GameWin(int turn){
  wattron(m_pWindow, COLOR_PAIR(2));
  mvwprintw(m_pWindow, 5, 1, " CONGRATURATION !! TURN : ");
  mvwprintw(m_pWindow, 5, 26, "%d", turn);
  wattroff(m_pWindow, COLOR_PAIR(2));
  wrefresh(m_pWindow);
}

void StatPane::ShipDestroyed(string ShipName){
  char shipname[ShipName.size() + 1];
  int i;
  for (i = 0; i < ShipName.size(); i++) {
    shipname[i] = ShipName[i];
  }
  shipname[i] = NULL;

  if (ShipName[0] == 'X') {
    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 6, 1, "                          ");
    wattroff(m_pWindow, COLOR_PAIR(2));
    wrefresh(m_pWindow);
  }else{
    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 6, 1, " You Destroyed ");
    mvwprintw(m_pWindow, 6, 16, "%s", shipname);
    wattroff(m_pWindow, COLOR_PAIR(2));
    wrefresh(m_pWindow);
  }
}
