#include "BattleShipMap.h"

BattleShipMap::~BattleShipMap(){}

BattleShipMap::BattleShipMap(int y) : Pane(4, y, MAP_SIZE + 4, MAP_SIZE + 2){
  for (size_t i = 0; i < MAP_SIZE; i++) {
    for (size_t j = 0; j < MAP_SIZE; ++j) {
      m_pMapData[i][j] = '-';
    }
  }
  for (size_t i = 0; i < MAP_SIZE; ++i) {
    mvprintw(i + 1 + m_y, m_x - 1, "%c", 'A' + i);
    mvprintw(m_y + m_height, m_x + 2 + i, "%d", 1 + i);
  }
  mvwprintw(m_pWindow, 0, 4, "<MAP>");
}

void BattleShipMap::DrawAllMap(){
  wattron(m_pWindow, COLOR_PAIR(1));
  for (size_t i = 0; i < MAP_SIZE; ++i) {
    for (size_t j = 0; j < MAP_SIZE; ++j) {
      mvwprintw(m_pWindow, i+1, j+2, "%c", m_pMapData[i][j]);
    }
  }
  wattroff(m_pWindow, COLOR_PAIR(1));
  wrefresh(m_pWindow);
}

void BattleShipMap::DrawShip(int x, int y){
  wattron(m_pWindow,COLOR_PAIR(2));
  mvwprintw(m_pWindow,x+1,y+2,"%c", m_pMapData[x][y]);
  wattroff(m_pWindow,COLOR_PAIR(2));
  wrefresh(m_pWindow);
}
