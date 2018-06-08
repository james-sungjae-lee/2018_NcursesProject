#include "Attacker.hpp"

Attacker::Attacker(){
  m_pMap = new BattleShipMap(18);
  m_pMap -> Draw();
}

void Attacker::CheckHit(Position input, char HitOrMiss){
  m_pMap->m_mapData[input.x][input.y] = HitOrMiss;
  m_pMap->DrawShip(input.x, input.y);
}
