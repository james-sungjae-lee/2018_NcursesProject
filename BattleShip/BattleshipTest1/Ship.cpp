#include "Ship.h"

Ship::Ship(){}

Ship::~Ship(){}

string Ship::GetName(){
  return m_pShipName;
}

void Ship::MinusHP(){
  m_pHP--;
}

bool Ship::CheckDestroyed(){
  if (m_pHP <= 0) {
    return true;
  }else{
    return false;
  }
}

Position* Ship::GetPosition(){
  return m_pPosition;
}

void Ship::SetPosition(Position* p){
  m_pPosition = p;
}

int Ship::GetSize(){
   return m_pSize;
}
