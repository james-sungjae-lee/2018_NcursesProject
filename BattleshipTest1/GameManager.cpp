#include "GameManager.h"

GameManager::GameManager(){}

void GameManager::Init(){
  m_pAttacker = new Attacker();
  m_pDefender = new Defender();

  m_pAircraft = new Aircraft("Aircraft");
  m_pBattleship = new Battleship("Battleship");
  m_pCruiser = new Cruiser("Cruiser");
  m_pDestroyer1 = new Destroyer("Destroyer1");
  m_pDestroyer2 = new Destroyer("Destroyer2");

  getch();

  m_pDefender->SetShip(m_pAircraft);
  m_pDefender->SetShip(m_pBattleship);
  m_pDefender->SetShip(m_pCruiser);
  m_pDefender->SetShip(m_pDestroyer1);
  m_pDefender->SetShip(m_pDestroyer2);
}

bool GameManager::GameOver(){
  if (m_pAircraft->m_pHP == 0) {
    m_pAircraft->m_pDestroyed = true;
  }
  if (m_pBattleship->m_pHP == 0) {
    m_pBattleship->m_pDestroyed = true;
  }
  if (m_pCruiser->m_pHP == 0) {
    m_pCruiser->m_pDestroyed = true;
  }
  if (m_pDestroyer1->m_pHP == 0) {
    m_pDestroyer1->m_pDestroyed = true;
  }
  if (m_pDestroyer2->m_pHP == 0) {
    m_pDestroyer2->m_pDestroyed = true;
  }
  return m_pAircraft->m_pDestroyed && m_pBattleship->m_pDestroyed && m_pCruiser->m_pDestroyed && m_pDestroyer1->m_pDestroyed && m_pDestroyer2->m_pDestroyed;
}

void GameManager::MinusHP(Position p){
  for (size_t i = 0; i < m_pAircraft->GetSize(); i++) {
    if (m_pAircraft->m_pPosition[i].x == p.x && m_pAircraft->m_pPosition[i].y == p.y) {
      m_pAircraft->m_pHP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pBattleship->GetSize(); i++) {
    if (m_pBattleship->m_pPosition[i].x == p.x && m_pBattleship->m_pPosition[i].y == p.y) {
      m_pBattleship->m_pHP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pCruiser->GetSize(); i++) {
    if (m_pCruiser->m_pPosition[i].x == p.x && m_pCruiser->m_pPosition[i].y == p.y) {
      m_pCruiser->m_pHP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pDestroyer1->GetSize(); i++) {
    if (m_pDestroyer1->m_pPosition[i].x == p.x && m_pDestroyer1->m_pPosition[i].y == p.y) {
      m_pDestroyer1->m_pHP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pDestroyer2->GetSize(); i++) {
    if (m_pDestroyer2->m_pPosition[i].x == p.x && m_pDestroyer2->m_pPosition[i].y == p.y) {
      m_pDestroyer2->m_pHP--;
      return;
    }
  }
}

void GameManager::CheckMap(Position inPosition){
  HitOrMiss = m_pDefender->CheckHit(inPosition);
  if (HitOrMiss == HIT) {
    MinusHP(inPosition);
  }
  m_pAttacker->CheckHit(inPosition, HitOrMiss);
}

string GameManager::DestroyedCheck(Position inPosition){
  Position p = inPosition;
  if (HitOrMiss == MISS) {
    return "X";
  }else{
    for (size_t i = 0; i < m_pAircraft->GetSize(); i++) {
      if (m_pAircraft->GetPosition()[i].x == p.x && m_pAircraft->GetPosition()[i].y == p.y) {
        if (m_pAircraft->m_pHP == 0) {
          return m_pAircraft->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pBattleship->GetSize(); i++) {
      if (m_pBattleship->GetPosition()[i].x == p.x && m_pBattleship->GetPosition()[i].y == p.y) {
        if (m_pBattleship->m_pHP == 0) {
          return m_pBattleship->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pCruiser->GetSize(); i++) {
      if (m_pCruiser->GetPosition()[i].x == p.x && m_pCruiser->GetPosition()[i].y == p.y) {
        if (m_pCruiser->m_pHP == 0) {
          return m_pCruiser->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pDestroyer1->GetSize(); i++) {
      if (m_pDestroyer1->GetPosition()[i].x == p.x && m_pDestroyer1->GetPosition()[i].y == p.y) {
        if (m_pDestroyer1->m_pHP == 0) {
          return m_pDestroyer1->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pDestroyer2->GetSize(); i++) {
      if (m_pDestroyer2->GetPosition()[i].x == p.x && m_pDestroyer2->GetPosition()[i].y == p.y) {
        if (m_pDestroyer2->m_pHP == 0) {
          return m_pDestroyer2->GetName();
        }
      }
    }
    return "X";
  }
}
