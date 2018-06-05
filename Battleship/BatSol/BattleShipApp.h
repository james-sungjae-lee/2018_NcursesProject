//20153195 우현웅
//C++ BattleShip Project
//작성일자 2018-05-31

#ifndef __BATTLESHIPAPP_H__
#define __BATTLESHIPAPP_H__

#include "BattleShipMap.h"
#include "StatPane.h"
#include "InputStat.h"
#include "ncurses.h"
#include "Attacker.h"
#include "Defender.h"
#include "Point.h"

class CBattleShipApp{
public:
	CBattleShipApp();
	~CBattleShipApp();

	void Play();

protected:
	void Init();
	void Render();
	void Destroy();

protected:
	StatPane* m_pStatPane;
	InputPane* m_pInputPane;
	Attacker* a;
	Defender* d;
	int turn;
};

#endif
