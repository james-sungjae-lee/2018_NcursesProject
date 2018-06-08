// C++ BattleShip Project
// 작성일자 2018-06-09
// 학번 : 20132651 이름 : 이성재
#pragma once

#include "GameManager.h"
#include "InputPane.h"
#include "StatPane.h"
#include <cstdlib>
#include <ctime>
#include <vector>

class BattleShipApp{
public:
  BattleShipApp();
  ~BattleShipApp();
  void Play();
  void PlayAI();
  int turn;
  int lastTurn;

protected:
  void Init();
  void Render();
  void Update();
  void UpdateAI();
  void Destroy();
  Position GetInputAI();

  GameManager* m_pGameManager;
  StatPane* m_pStatPane;
  InputPane* m_pInputPane;

  Position input;
  string DestroyedShip;
  char AIAttackMap[8][8];
  std::vector<Position> nextAttack;

};
