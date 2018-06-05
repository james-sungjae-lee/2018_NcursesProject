#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height) : Pane(x,y,width,height)
{
		mvwprintw(m_pWindow,0,3,"< STATUS >");
		dstack = 0;
}

void StatPane::Draw(){
	wattron(m_pWindow,COLOR_PAIR(2));
	mvwprintw(m_pWindow,1,2,"TURN :");
	mvwprintw(m_pWindow,2,2,"AIRCRAFT : AAAAA");
	mvwprintw(m_pWindow,3,2,"BATTLESHIP : BBBB");
	mvwprintw(m_pWindow,4,2,"CRUISER : CCC");
	mvwprintw(m_pWindow,5,2,"DESTROYER : DD DD");
	wattroff(m_pWindow,COLOR_PAIR(2));

	wrefresh(m_pWindow);
}

void StatPane::updateDestroy(char type){
	wattron(m_pWindow,COLOR_PAIR(4));
	switch (type) {
		case 'A':
			mvwprintw(m_pWindow,2,2,"AIRCRAFT : DESTROY!");
			break;
		case 'B' :
			mvwprintw(m_pWindow,3,2,"BATTLESHIP : DESTROY!");
			break;
		case 'C':
			mvwprintw(m_pWindow,4,2,"CRUISER : DESTROY!");
			break;
		case 'D':
			dstack++;
			if(dstack == 1){
				mvwprintw(m_pWindow,5,14,"DD");
			}
			else{
				mvwprintw(m_pWindow,5,2,"DESTROY : DESTROY!");
			}
			break;
	}
	wattroff(m_pWindow,COLOR_PAIR(4));
	wrefresh(m_pWindow);
}

void StatPane::updateTurn(int turn){
	wattron(m_pWindow,COLOR_PAIR(2));
	stringstream strs;
	strs << turn;
	string temp_str = strs.str();
	char* char_type = (char*) temp_str.c_str();
	mvwprintw(m_pWindow,1,10,char_type);
	wattroff(m_pWindow,COLOR_PAIR(2));
	wrefresh(m_pWindow);
}
