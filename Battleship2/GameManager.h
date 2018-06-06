// C++ Battleship Project Version 2
// GameManager.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "Attacker.h"
#include "Defender.h"
#include "Enums.h"

#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"

#include <string>
using namespace std;

class GameManager{
public:
  GameManager();
  void Init();    // Attacker 와 Defender의 맵 제작
  bool GameOver();
  void CheckMap(Position inPosition);  // 하나의 포지션을 받아, 해당 포지션으로 맵에 체크함
  void MinusHP(Position inPosition);   // 해당 포지션을 가진 Ship의 체력을 감소시킨다.
  string DestroyedCheck(Position inPosition); // 해당 포지션을 가진 Ship이 파괴되었는지 확인하고, 파괴되었다면 배의 이름을 반환한다.

  Attacker* m_pAttacker;
  Defender* m_pDefender;

  Aircraft* m_pAircraft;
  Battleship* m_pBattleship;
  Cruiser* m_pCruiser;
  Destroyer* m_pDestroyer1;
  Destroyer* m_pDestroyer2;

  Position input;
  HitResult HitOrMiss;
};
