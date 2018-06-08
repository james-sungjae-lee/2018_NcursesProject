// C++ BattleShip Project
// 작성일자 2018-05-30
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Position.h"
#include <string>
using namespace std;

enum ShipType { SHIP_NONE, AIRCRAFT, BATTLESHIP, CRUISER, DESTROYER, SHIP_CANT_PLACE };

class Ship{
public:
  Ship();
  ~Ship();

  ShipType GetType();
  string GetName();
  Position *GetPosition();
  int GetSize();

  void minusHP();
  bool destroyed();
  void SetPosition(Position *p);

  int m_HP; // 배의 체력
  string m_Name; // 배의 이름
  Position *m_Position; // 배의 포지션
  int m_Size; // 배의 사이즈
  ShipType m_Type; // 배의 타입
  bool Destroyed;

};
