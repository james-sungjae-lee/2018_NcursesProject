//20153195 우현웅
//C++ BattleShip Project
//작성일자 2018-05-31

#ifndef __BATTLESHIPMAP_H__
#define __BATTLESHIPMAP_H__

#include "Pane.h"
#include "ncurses.h"

#define MAP_SIZE 8

class CBattleShipMap : Pane{
	int nameSelector;
public:
	CBattleShipMap(int n = 3);
	~CBattleShipMap();

	void Draw();
	void drawStatus(int,int);
	void drawShip(int,int);

	char m_mapData[MAP_SIZE][MAP_SIZE];
};

#endif
