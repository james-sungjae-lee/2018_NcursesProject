#include "Attacker.hpp"

Attacker::Attacker(){
  m_pMap = new BattleShipMap(18);
  m_pMap -> Draw();
}

void Attacker::CheckHit(string input, char HitOrMiss){
  int x = input[0] - 'A';
  int y = input[1] - '0';
  m_pMap->m_mapData[x][y] = HitOrMiss;
  m_pMap->DrawShip(x, y);
}
