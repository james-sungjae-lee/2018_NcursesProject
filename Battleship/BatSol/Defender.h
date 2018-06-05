//20153195 우현웅
//C++ BattleShip Project
//작성일자 2018-06-01

#pragma once
#include "BattleShipMap.h"
#include "Ship.h"
#include "Point.h"
#include "cstdlib"
#include "ctime"

class Defender{
public:
  Defender();
  ~Defender();
  void setShip(Ship *s);
  bool isHit(int,int);
  void setting();
  bool gameset();
  bool isDestroyed(int,int);
  Ship* getDestroyedShip(int,int);
  char getType(int,int);

private:
  Ship *AirCraft;
  Ship *BattleShip;
  Ship *Cruiser;
  Ship *Destroyer1;
  Ship *Destroyer2;

  CBattleShipMap* dmap;

};
