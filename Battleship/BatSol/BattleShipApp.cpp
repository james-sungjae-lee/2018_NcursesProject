#include "BattleShipApp.h"

CBattleShipApp::CBattleShipApp(){}
CBattleShipApp::~CBattleShipApp(){}

void CBattleShipApp::Init(){
		initscr();
		start_color();
		cbreak();
		refresh();

		//color setting
		init_pair(1, COLOR_GREEN,COLOR_BLACK);
		init_pair(2, COLOR_CYAN, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
		init_pair(4,COLOR_RED,COLOR_BLACK);
		init_pair(5,COLOR_RED,COLOR_WHITE);
		init_pair(6,COLOR_BLUE,COLOR_WHITE);

		a = new Attacker();
		d = new Defender();
		d->setting();
		m_pStatPane = new StatPane(30,3,30,7);
		m_pInputPane = new InputPane(30,15,30,4);
		turn = 0;
}

void CBattleShipApp::Play(){
	Point p;
	Init();
	Render();
	while(!d->gameset()){
		m_pStatPane->updateTurn(turn);
		turn++;
		m_pInputPane->attack(p);
		a->inputAttack(p.x,p.y,d);
		if(d->isDestroyed(p.x,p.y)){
			char t = d->getType(p.x,p.y);
			m_pStatPane->updateDestroy(t);

		}

	}
	Destroy();
}

void CBattleShipApp::Render(){
	mvprintw(1,1,"<< Battle Ship Game >>");

	m_pStatPane->Draw();
	m_pInputPane->Draw();

	refresh();
}

void CBattleShipApp::Destroy(){
	getch();
	endwin();
}
