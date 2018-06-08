// C++ BattleShip Project
// 작성일자 2018-05-29
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Player.hpp"
#include "Ship.hpp"
#include <cstdlib>
#include <ctime>

class Defender : public Player{
public:
  Defender();
  void setShip(Ship* ship);
  char CheckHit(string input);
};
