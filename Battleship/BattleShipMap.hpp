// C++ BattleShip Project
// 작성일자 2018-05-25
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Pane.hpp"

#define Map_SIZE 8

class BattleShipMap : Pane {
public:
  BattleShipMap(int y);
  ~BattleShipMap();

  void Draw();

  char m_mapData[Map_SIZE][Map_SIZE];
};
