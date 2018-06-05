//20153195 우현웅
//C++ BattleShip Project
//작성일자 2018-05-31

#ifndef __INPUTSTAT_H__
#define __INPUTSTAT_H__


#include "Pane.h"
#include "ncurses.h"
#include "Point.h"

class InputPane: Pane
{
public:
	InputPane(int x,int y,int width,int height);
	~InputPane();
	void attack(Point &p);

	virtual void Draw();
};

#endif
