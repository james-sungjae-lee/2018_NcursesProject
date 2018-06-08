#include "Defender.h"
Defender::Defender(){
  m_DefenderMap = new BattleShipMap(4);
  m_DefenderMap -> DrawAllMap();
}

void Defender::SetShip(Ship* newShip){
  srand((unsigned int)time(NULL));  // 랜덤 시드값을 시간으로 설정
  int row_col;                      // 가로 - 세로 배치 여부를 랜덤으로 정함
  int x, y;                         // 실제 배를 표시할 위치의 좌표?
  Position *p = new Position[newShip->GetSize()];

  while (true) {

    bool check = true;
    row_col = rand()%2;

    if (row_col == 0) {
      x = rand()%(8 - newShip->GetSize() + 1);
      y = rand()%8;

      for (size_t i = 0; i < newShip->GetSize(); i++) {
        if (m_DefenderMap->m_pMapData[x + i][y] != '-') {
          check = false;
        }
      }
    if (check == false) {
      continue;
    }
    for (size_t i = 0; i < newShip->GetSize(); i++) {
      m_DefenderMap->m_pMapData[x + i][y] = newShip->GetName()[0];
      m_DefenderMap->DrawShip(x + i, y);
      p[i].x = x + i;
      p[i].y = y;
    }
    newShip->SetPosition(p);
  }else if(row_col == 1){
      x = rand()%8;
      y = rand()%(8 - newShip->GetSize() + 1);

      for (size_t i = 0; i < newShip->GetSize(); i++) {
        if (m_pMap->m_pMapData[x][y + i] != '-') {
          check = false;
        }
      }
      if (check == false) {
        continue;
      }
      for (size_t i = 0; i < newShip->GetSize(); i++) {
        m_DefenderMap->m_pMapData[x][y+i] = newShip->GetName()[0];
        m_DefenderMap->DrawShip(x, y+i);
        p[i].x = x;
        p[i].y = y + i;
      }
      newShip->SetPosition(p);
    }
    break;
  }
}

HitResult Defender::CheckHit(Position inPosition){
  if (m_DefenderMap->m_pMapData[inPosition.x][inPosition.y] == '-') {
    return MISS;
  }else{
    return HIT;
  }
}
