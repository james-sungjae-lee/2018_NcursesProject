// C++ Battleship Project Version 2
// Pane.h
// 작성일자 : 2018_06_06
// 학번 : 20132651
// 이름 : 이 성 재

#pragma once
#include <ncurses.h>

class Pane{
public:
  Pane(int x, int y, int width, int height);
  virtual ~Pane();
  virtual void Draw();

protected:
  int m_width, m_height;
  int m_x, m_y;
  WINDOW* m_pWindow;
};
