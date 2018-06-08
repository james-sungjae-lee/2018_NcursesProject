// C++ BattleShip Project
// 작성일자 2018-06-02
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Attacker.h"   // 공격자 객체 생성을 위한 헤더파일
#include "Defender.h"   // 수비자 객체 생성을 위한 헤더파일

#include "Aircraft.h"   // 전투함들의 객체 생성을 위한 헤더파일
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
