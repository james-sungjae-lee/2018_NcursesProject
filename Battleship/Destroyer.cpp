#include "Destroyer.hpp"

Destroyer::Destroyer(string shipName) : Ship(){
  this->m_HP = 2;
  this->m_Name = shipName;
  this->m_Type = DESTROYER;
  this->m_Size = 2;
  this->m_Position = new Position[2];
}
