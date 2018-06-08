#include "Aircraft.h"

Aircraft::Aircraft(string shipName) : Ship(){
  this->m_pSize = 5;
  this->m_pShipName = shipName;
  this->m_pShipType = AIRCRAFT;
  this->m_pHP = m_pSize;
  this->m_pPosition = new Position[m_pSize];
  this->m_pDestroyed = false;
}
