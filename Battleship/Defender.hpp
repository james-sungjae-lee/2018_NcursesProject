// C++ BattleShip Project
// 작성일자 2018-05-29
// 학번 : 20132651 이름 : 이성재
#pragma once
#include "Player.hpp"
#include "Ship.hpp"
class Defender : public Player{
public:
  Defender();
  void setShip(Ship* s){
    for (size_t i = 0; i < s->GetSize(); i++) {
      m_pMap->m_mapData[s->m_Position[i].x][s->m_Position[i].y] = s->m_Name[0];
    }
    m_pMap->Draw();
  }
};
