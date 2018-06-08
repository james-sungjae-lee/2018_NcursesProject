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
  Position GetInputAI();

  GameManager* m_pGameManager;
  StatPane* m_pStatPane;
  InputPane* m_pInputPane;

  Position input;
  int turn;
  string DestroyedShip;
  char AIAttackMap[8][8];
  std::vector<Position> nextAttack;

};
