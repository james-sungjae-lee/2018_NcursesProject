// C++ BattleShip Project
// 작성일자 2018-06-08
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Attacker.h"
#include "Defender.h"

#include "Aircraft.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"

#include <string>

class GameManager{
public:
  GameManager();
  void Init();
  bool GameOver();
  void CheckMap(Position input);
  void MinusHP(Position p);
  string DestroyedCheck(Position input);

  Attacker* m_pAttacker;
  Defender* m_pDefender;

  Aircraft* m_pAircraft;
  Battleship* m_pBattleship;
  Cruiser* m_pCruiser;
  Destroyer* m_pDestroyer1;
  Destroyer* m_pDestroyer2;

  Position input;
  char HitOrMiss;
};
