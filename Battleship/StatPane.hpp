// C++ BattleShip Project
// 작성일자 2018-05-30
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Pane.hpp"

class StatPane : Pane{
public:
  StatPane(int x, int y, int width, int height);
  ~StatPane();
  virtual void Draw();
  void DrawTurn(int turn);
};
