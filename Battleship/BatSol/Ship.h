//20153195 우현웅
//C++ BattleShip Project
//작성일자 2018-06-01

#pragma once
#include "Point.h"

class Ship{
public:
  Ship(char type);
  ~Ship();

  bool isDestroyed();
  void getDamage();
  void getPosition(Point *m);
  void setPosition(Point *m);
  int getSize();
  char getType();


private:
  int size;
  char type;
  int hp;
  Point *p;

};
