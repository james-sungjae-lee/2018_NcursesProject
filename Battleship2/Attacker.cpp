#include "Attacker.h"

Attacker::Attacker(){
  m_AttackerMap = new BattleShipMap(18);
  m_AttackerMap -> DrawAllMap();
}

void Attacker::CheckHit(Position inPosition, HitResult HitOrMiss){
  if (HitOrMiss == HIT) {
    m_AttackerMap -> m_pMapData[inPosition.x][inPosition.y] = 'H';
    m_AttackerMap -> DrawShip(inPosition.x, inPosition.y);
  }else if (HitOrMiss == MISS) {
    m_AttackerMap -> m_pMapData[inPosition.x][inPosition.y] = 'M';
    m_AttackerMap -> DrawShip(inPosition.x, inPosition.y);
  }
}
