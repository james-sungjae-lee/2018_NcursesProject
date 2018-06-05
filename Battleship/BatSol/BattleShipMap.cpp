#include "BattleShipMap.h"


#define MAP_SIZE 8

CBattleShipMap::CBattleShipMap(int n)
	:Pane(4,n, MAP_SIZE + 4, MAP_SIZE +2),nameSelector(n)
{
	char *name;
	int pointx = 2;
	switch (nameSelector) {
		case 4:
			name = "< MAP >";
			break;
		case 15:
			name = "<Attacker>";
			pointx = 1;
			break;
		case 3:
			name = "<Defender>";
			pointx =1;
			break;
	}
	 for(int i=0;i<MAP_SIZE;i++){
		 for(int j=0;j<MAP_SIZE;j++){
			 m_mapData[i][j] = '0';
		 }
	 }

	 for(int i=0;i<MAP_SIZE;i++){
		 mvprintw(i+1+m_y, m_x -1, "%c", 'A' + i);
		 mvprintw(m_y + m_height, m_x + 2 + i, "%d", 1+i);
	 }

	 mvwprintw(m_pWindow,0,pointx,name);
}

CBattleShipMap::~CBattleShipMap(){}

void CBattleShipMap::Draw(){
	wattron(m_pWindow, COLOR_PAIR(1));
	for(int i=0;i<MAP_SIZE; ++i){
		for(int j=0;j<MAP_SIZE;++j){
			mvwprintw(m_pWindow, i+1, j+2, "%c", m_mapData[i][j]);
		}
	}
	wattroff(m_pWindow, COLOR_PAIR(1));

	wrefresh(m_pWindow);
}

void CBattleShipMap::drawStatus(int x, int y){
	wattron(m_pWindow,COLOR_PAIR(5));
	mvwprintw(m_pWindow,x+1,y+2,"%c",m_mapData[x][y]);
	wattroff(m_pWindow,COLOR_PAIR(5));
	wrefresh(m_pWindow);
}

void CBattleShipMap::drawShip(int x,int y){
	wattron(m_pWindow,COLOR_PAIR(6));
	mvwprintw(m_pWindow,x+1,y+2,"%c",m_mapData[x][y]);
	wattroff(m_pWindow,COLOR_PAIR(6));
	wrefresh(m_pWindow);
}
