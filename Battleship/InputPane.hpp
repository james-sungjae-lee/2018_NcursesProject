// C++ BattleShip Project
// 작성일자 2018-05-25
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Pane.hpp"
#include "Position.hpp"
#include <string>
using namespace std;

class InputPane : public Pane{
public:
  InputPane(int x, int y, int width, int height);
  ~InputPane();

  virtual void Draw();
  string GetInput();
};
