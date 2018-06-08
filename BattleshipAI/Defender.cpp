#include "Defender.hpp"
Defender::Defender(){
  m_pMap = new BattleShipMap(4);
  m_pMap -> Draw();
}

void Defender::setShip(Ship* ship){
  srand((unsigned int)time(NULL));  // 랜덤 시드값을 시간으로 설정
  int row_col;                      // 가로 - 세로 배치 여부를 랜덤으로 정함
  int x, y;                         // 실제 배를 표시할 위치의 좌표?
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

char Defender::CheckHit(Position input){
  char HitOrMiss;
  if (m_pMap->m_mapData[input.x][input.y] == '-') {
    HitOrMiss = 'M';
    return HitOrMiss;
  }else{
    HitOrMiss = 'H';
    return HitOrMiss;
  }
}
