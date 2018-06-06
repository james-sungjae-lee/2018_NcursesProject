// C++ Battleship Project Version 2
// Ship.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "Position.h"
#include <string>
using namespace std;

class Ship{
public:
  enum ShipType { AIRCRAFT, BATTLESHIP, CRUISER, DESTROYER };

  Ship();
  ~Ship();

  string GetName();
  Position *GetPosition();
  int GetSize();

  void MinusHP();
  bool CheckDestroyed();
  void SetPosition(Position *p);

  int m_pHP;
  int m_pSize;
  bool m_pDestroyed;
  string m_pShipName;
  Position* m_pPosition;
  ShipType m_pShipType;
};
