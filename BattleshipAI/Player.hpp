// C++ BattleShip Project
// 작성일자 2018-05-29
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "BattleShipMap.hpp"
class Player{
public:
  Player();
  ~Player();

  BattleShipMap *m_pMap;
};
