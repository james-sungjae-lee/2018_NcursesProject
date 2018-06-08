#include "Cruiser.hpp"

Cruiser::Cruiser(string shipName) : Ship() {
  this->m_HP = 3;
  this->m_Name = shipName;
  this->m_Type = CRUISER;
  this->m_Size = 3;
  this->m_Position = new Position[3];
  this->Destroyed = false;
}
