//20153195 우현웅
//C++ BattleShip Project
//작성일자 : 2018-06-01

#pragma once
#include "BattleShipMap.h"
#include "Defender.h"
#include "Ship.h"
#include "Point.h"

class Attacker{
  CBattleShipMap *amap;
public:
  Attacker();
  ~Attacker();
  void inputAttack(int,int,Defender *d);
  void showHit(int x, int y);
  void showDestroy(Ship *s);
  void showMiss(int x, int y);

};
