#include "Attacker.hpp"

Attacker::Attacker(){
  m_pMap = new BattleShipMap(18);
  m_pMap -> Draw();
}
