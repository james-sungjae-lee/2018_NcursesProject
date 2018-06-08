// C++ BattleShip Project
// 작성일자 2018-05-29
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Player.hpp"
#include <string>
using namespace std;

class Attacker : public Player{
  BattleShipMap *attackMap;
public:
  Attacker();
  void CheckHit(string input, char HitOrMiss);
};
