#include "Defender.hpp"
Defender::Defender(){
  m_pMap = new BattleShipMap(4);
  m_pMap -> Draw();
}

void Defender::setShip(Ship* ship){
  int row_col;
  int x, y;
  Position *p = new Position[ship->GetSize()];

  while (true) {

    bool check = true;
    row_col = rand()%2;

    if (row_col == 0) {
      x = rand()%(8 - ship->GetSize() + 1);
      y = rand()%8;

      for (size_t i = 0; i < ship->GetSize(); i++) {
        if (m_pMap->m_mapData[x + i][y] != '-') {
          check = false;
        }
      }
    if (check == false) {
      continue;
    }
    for (size_t i = 0; i < ship->GetSize(); i++) {
      m_pMap->m_mapData[x + i][y] = ship->GetName()[0];
      m_pMap->DrawShip(x + i, y);
      p[i].x = x + i;
      p[i].y = y;
    }
    ship->SetPosition(p);
  }else if(row_col == 1){
      x = rand()%8;
      y = rand()%(8 - ship->GetSize() + 1);

      for (size_t i = 0; i < ship->GetSize(); i++) {
        if (m_pMap->m_mapData[x][y + i] != '-') {
          check = false;
        }
      }
      if (check == false) {
        continue;
      }
      for (size_t i = 0; i < ship->GetSize(); i++) {
        m_pMap->m_mapData[x][y+i] = ship->GetName()[0];
        m_pMap->DrawShip(x, y+i);
        p[i].x = x;
        p[i].y = y + i;
      }
      ship->SetPosition(p);
    }
    break;
  }
}

char Defender::CheckHit(string input){
  int x = input[0] - 'A';
  int y = input[1] - '0';
  char HitOrMiss;

  if (m_pMap->m_mapData[x][y] == '-') {
    HitOrMiss = 'M';
    return HitOrMiss;
  }else{
    HitOrMiss = 'H';
    return HitOrMiss;
  }
}
