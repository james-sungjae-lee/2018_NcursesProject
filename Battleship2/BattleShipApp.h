// C++ Battleship Project Version 2
// BattleShipApp.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "GameManager.h"
#include "InputPane.h"
#include "StatPane.h"

class BattleShipApp{
public:
  BattleShipApp();
  ~BattleShipApp();
  void Play();

protected:
  void Init();
  void Render();
  void Update();
  void Destroy();
  void SelectMode();

  GameManager* m_pGameManager;
  StatPane* m_pStatPane;
  InputPane* m_pInputPane;

  Position input;
  string DestroyedShip;
  int turn;
  bool gameQuit;
  enum GameMode { PLAY_INPUT, PLAY_RANDOM, PLAY_FOLLOW_AI };
  GameMode myGameMode;
};
