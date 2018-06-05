#include "BattleShipMap.hpp"

BattleShipMap::BattleShipMap(int y) : Pane(4, y, Map_SIZE + 4, Map_SIZE + 2){
  for (size_t i = 0; i < Map_SIZE; i++) {
    for (size_t j = 0; j < Map_SIZE; ++j) {
      m_mapData[i][j] = '-';
    }
  }

  for (size_t i = 0; i < Map_SIZE; ++i) {
    mvprintw(i + 1 + m_y, m_x - 1, "%c", 'A' + i);
    mvprintw(m_y + m_height, m_x + 2 + i, "%d", 1 + i);
  }

  mvwprintw(m_pWindow, 0, 4, "<MAP>");
}

BattleShipMap::~BattleShipMap(){
}

void BattleShipMap::Draw(){
  wattron(m_pWindow, COLOR_PAIR(1));
  for (size_t i = 0; i < Map_SIZE; ++i) {
    for (size_t j = 0; j < Map_SIZE; ++j) {
      mvwprintw(m_pWindow, i+1, j+2, "%c", m_mapData[i][j]);
    }
  }
  wattroff(m_pWindow, COLOR_PAIR(1));
  wrefresh(m_pWindow);
}

void BattleShipMap::DrawShip(int x, int y){
  wattron(m_pWindow,COLOR_PAIR(1));
  mvwprintw(m_pWindow,x+1,y+2,"%c",m_mapData[x][y]);
  wattroff(m_pWindow,COLOR_PAIR(1));
  wrefresh(m_pWindow);
}
