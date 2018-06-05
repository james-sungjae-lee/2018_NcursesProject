// C++ BattleShip Project
// 작성일자 2018-05-25
// 학번 : 20132651 이름 : 이성재

#pragma once
#include "GameManager.hpp"
#include "InputPane.hpp"
#include "StatPane.hpp"

class BattleShipApp{

public:
  BattleShipApp();        // BattleShipApp 의 생성자
  ~BattleShipApp();       // BattleShipApp 의 소멸자
  void Play();            // 전체 함수들을 실행시키는 Play 함수

protected:
  void Init();
  void Render();
  void Update();
  void Destroy();

  GameManager* m_pGameManager;
  StatPane* m_pStatPane;
  InputPane* m_pInputPane;

  string input;
  int turn;
};
