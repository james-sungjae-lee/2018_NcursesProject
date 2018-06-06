// C++ Battleship Project Version 2
// StatPane.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "Pane.h"
#include <string>
using namespace std;

class StatPane : Pane{
public:
  StatPane(int x, int y, int width, int height);
  ~StatPane();
  virtual void Draw();
  void DrawTurn(int turn);
  void GameWin(int turn);
  void ShipDestroyed(string ShipName);
};
