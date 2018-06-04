#include "Aircraft.hpp"

Aircraft::Aircraft(string shipName) : Ship(){
  this->m_HP = 5;
  this->m_Name = shipName;
  this->m_Type = AIRCRAFT;
  this->m_Size = 5;
  this->m_Position = new Position[5];
}
