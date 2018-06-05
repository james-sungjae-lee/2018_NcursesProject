#include "Ship.h"

Ship::Ship(char t)
  :type(t)
{
  switch (type) {
    case 'A':
      size = 5;
      break;
    case 'B':
      size = 4;
      break;
    case 'C':
      size = 3;
      break;
    case 'D':
      size = 2;
      break;
    default:
      size = 0;
      break;
  }
  hp = size;

  p = new Point[size];
}

Ship::~Ship(){
  delete p;
}

bool Ship::isDestroyed(){
  if(hp == 0){
    return true;
  }
  return false;
}

void Ship::getDamage(){
  hp--;
}

void Ship::getPosition(Point *m){
  for(int i = 0; i < size; i ++){
    m[i].x = p[i].x;
    m[i].y = p[i].y;
  }
}

void Ship::setPosition(Point *m){
  for (int i  = 0; i  < size; i++) {
    p[i].x = m[i].x;
    p[i].y = m[i].y;
  }
}

int Ship::getSize(){
  return size;
}

char Ship::getType(){
  return type;
}
