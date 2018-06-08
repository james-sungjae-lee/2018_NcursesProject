// C++ Battleship Project Version 2
// BattleShipMap.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "Pane.h"
#define MAP_SIZE 8

class BattleShipMap : Pane{
public:
  BattleShipMap(int y);
  ~BattleShipMap();

  void DrawAllMap();
  void DrawShip(int x, int y);

  char m_pMapData[MAP_SIZE][MAP_SIZE];
};
