// C++ Battleship Project Version 2
// Defender.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "Player.h"
#include "Enums.h"
#include "Ship.h"
#include <cstdlib>
#include <ctime>

class Defender : public Player{
public:
  Defender();
  void SetShip(Ship* newShip);
  HitResult CheckHit(Position inPosition);
  BattleShipMap* m_DefenderMap;
};
