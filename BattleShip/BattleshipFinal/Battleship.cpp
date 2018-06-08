#include "Battleship.h"

Battleship::Battleship(string shipName) : Ship(){
  this->m_HP = 4;
  this->m_Name = shipName;
  this->m_Type = BATTLESHIP;
  this->m_Size = 4;
  this->m_Position = new Position[4];
  this->Destroyed = false;
}
