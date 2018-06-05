//20153195 우현웅
//C++ BattleShip Project
//작성일자 2018-05-31

#ifndef __PANE_H__
#define __PANE_H__

#include "ncurses.h"

class Pane{
public:
	Pane(int x, int y, int widht, int height);
	~Pane();
	virtual void Draw();

protected:
	int m_width, m_height;
	int m_x, m_y;
	WINDOW* m_pWindow;
};

#endif
