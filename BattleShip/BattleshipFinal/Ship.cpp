#include "Ship.h"

Ship::Ship(){
}

Ship::~Ship(){
}

ShipType Ship::GetType(){
  return m_Type;
}

string Ship::GetName(){
  return m_Name;
}

void Ship::minusHP(){
  m_HP--;
}

bool Ship::destroyed(){
  if (m_HP <= 0) {
    return true;
  }else{
    return false;
  }
}

Position *Ship::GetPosition(){
  return m_Position;
}

void Ship::SetPosition(Position *p){
  m_Position = p;
}

int Ship::GetSize(){
  return m_Size;
}
