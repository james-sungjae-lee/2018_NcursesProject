// C++ BattleShip Project
// 작성일자 2018-05-25
// 학번 : 20132651 이름 : 이성재
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
