// C++ BattleShip Project
// 작성일자 2018-06-02
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Attacker.hpp"   // 공격자 객체 생성을 위한 헤더파일
#include "Defender.hpp"   // 수비자 객체 생성을 위한 헤더파일

#include "Aircraft.hpp"   // 전투함들의 객체 생성을 위한 헤더파일
#include "Battleship.hpp"
#include "Cruiser.hpp"
#include "Destroyer.hpp"

#include <string>

class GameManager{
public:
  GameManager();
  void Init();
  bool GameOver();
  void CheckMap(string);

  Attacker* m_pAttacker;
  Defender* m_pDefender;

  Aircraft* m_pAircraft;
  Battleship* m_pBattleship;
  Cruiser* m_pCruiser;
  Destroyer* m_pDestroyer1;
  Destroyer* m_pDestroyer2;

  string input;
};
