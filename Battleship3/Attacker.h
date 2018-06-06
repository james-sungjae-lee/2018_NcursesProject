// C++ Battleship Project Version 2
// Attacker.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "Player.h"
#include "Enums.h"
#include "Position.h"
#include <string>
using namespace std;

class Attacker : public Player{
public:
  BattleShipMap* m_AttackerMap;
  Attacker();
  void CheckHit(Position inPosition, HitResult HitOrMiss);
};
