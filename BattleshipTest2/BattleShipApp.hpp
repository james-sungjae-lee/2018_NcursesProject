// C++ BattleShip Project
// 작성일자 2018-05-25
// 학번 : 20132651 이름 : 이성재

#pragma once
#include "GameManager.hpp"
#include "InputPane.hpp"
#include "StatPane.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>

class BattleShipApp{

public:
  BattleShipApp();
  ~BattleShipApp();
  void Play();
  void PlayAI();

protected:
  void Init();
  void Render();
  void Update();
  void UpdateAI();
  void Destroy();
  string GetInputAI();

  GameManager* m_pGameManager;
  StatPane* m_pStatPane;
  InputPane* m_pInputPane;

  string input;
  int turn;
  string DestroyedShip;
  int AiAttackMap[8][8];
};
