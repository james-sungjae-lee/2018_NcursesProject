#include "Defender.hpp"
Defender::Defender(){
  m_pMap = new BattleShipMap(4);
  m_pMap -> Draw();
}
