// C++ Battleship Project Version 2
// InputPane.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include "Pane.h"
#include "Position.h"
#include <string>
using namespace std;

class InputPane : public Pane{
public:
  InputPane(int x, int y, int width, int height);
  ~InputPane();

  virtual void Draw();
  Position GetInput();
};
