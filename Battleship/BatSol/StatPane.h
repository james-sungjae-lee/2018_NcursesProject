//20153195 우현웅
//C++ BattleShip Project
//작성일자 2018-05-31

#ifndef __STATPANE_H__
#define __STATPANE_H__

#include "StatPane.h"
#include "InputStat.h"
#include "Pane.h"
#include "ncurses.h"
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

class StatPane : Pane{
	int dstack;
	public:
			StatPane(int x, int y, int width, int height);
			~StatPane();
			void updateDestroy(char);
			void updateTurn(int);

			virtual void Draw();
};



#endif
