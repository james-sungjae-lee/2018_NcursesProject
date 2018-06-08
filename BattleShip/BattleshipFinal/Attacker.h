// C++ BattleShip Project
// 작성일자 2018-05-29
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Player.h"
#include "Position.h"
#include <string>
using namespace std;

class Attacker : public Player{
public:
  BattleShipMap *m_pMap;
  Attacker();
  void CheckHit(Position input, char HitOrMiss);
};
