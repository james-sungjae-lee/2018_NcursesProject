#include "Cruiser.h"

Cruiser::Cruiser(string shipName) : Ship(){
  this->m_pSize = 3;
  this->m_pShipName = shipName;
  this->m_pShipType = CRUISER;
  this->m_pHP = m_pSize;
  this->m_pPosition = new Position[m_pSize];
  this->m_pDestroyed = false;
}
