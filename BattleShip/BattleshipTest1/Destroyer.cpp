#include "Destroyer.h"

Destroyer::Destroyer(string shipName) : Ship(){
  this->m_pSize = 2;
  this->m_pShipName = shipName;
  this->m_pShipType = DESTROYER;
  this->m_pHP = m_pSize;
  this->m_pPosition = new Position[m_pSize];
  this->m_pDestroyed = false;
}
