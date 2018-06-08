#include "Battleship.h"

Battleship::Battleship(string shipName) : Ship(){
  this->m_pSize = 4;
  this->m_pShipName = shipName;
  this->m_pShipType = BATTLESHIP;
  this->m_pHP = m_pSize;
  this->m_pPosition = new Position[m_pSize];
  this->m_pDestroyed = false;
}
