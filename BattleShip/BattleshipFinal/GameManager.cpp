#include "GameManager.h"

GameManager::GameManager(){
}

void GameManager::Init(){
  m_pAttacker = new Attacker();
  m_pDefender = new Defender();

  m_pAircraft = new Aircraft("Aircraft");
  m_pBattleship = new Battleship("Battleship");
  m_pCruiser = new Cruiser("Cruiser");
  m_pDestroyer1 = new Destroyer("Destroyer1");
  m_pDestroyer2 = new Destroyer("Destroyer2");

  getch();

  m_pDefender->setShip(m_pAircraft);
  m_pDefender->setShip(m_pBattleship);
  m_pDefender->setShip(m_pCruiser);
  m_pDefender->setShip(m_pDestroyer1);
  m_pDefender->setShip(m_pDestroyer2);

}

bool GameManager::GameOver(){
  if (m_pAircraft->m_HP == 0) {
    m_pAircraft->Destroyed = true;
  }
  if (m_pBattleship->m_HP == 0) {
    m_pBattleship->Destroyed = true;
  }
  if (m_pCruiser->m_HP == 0) {
    m_pCruiser->Destroyed = true;
  }
  if (m_pDestroyer1->m_HP == 0) {
    m_pDestroyer1->Destroyed = true;
  }
  if (m_pDestroyer2->m_HP == 0) {
    m_pDestroyer2->Destroyed = true;
  }
  return m_pAircraft->Destroyed && m_pBattleship->Destroyed && m_pCruiser->Destroyed && m_pDestroyer1->Destroyed && m_pDestroyer2->Destroyed;
}

void GameManager::MinusHP(Position p){
  for (size_t i = 0; i < m_pAircraft->GetSize(); i++) {
    if (m_pAircraft->m_Position[i].x == p.x && m_pAircraft->m_Position[i].y == p.y) {
      m_pAircraft->m_HP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pBattleship->GetSize(); i++) {
    if (m_pBattleship->m_Position[i].x == p.x && m_pBattleship->m_Position[i].y == p.y) {
      m_pBattleship->m_HP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pCruiser->GetSize(); i++) {
    if (m_pCruiser->m_Position[i].x == p.x && m_pCruiser->m_Position[i].y == p.y) {
      m_pCruiser->m_HP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pDestroyer1->GetSize(); i++) {
    if (m_pDestroyer1->m_Position[i].x == p.x && m_pDestroyer1->m_Position[i].y == p.y) {
      m_pDestroyer1->m_HP--;
      return;
    }
  }
  for (size_t i = 0; i < m_pDestroyer2->GetSize(); i++) {
    if (m_pDestroyer2->m_Position[i].x == p.x && m_pDestroyer2->m_Position[i].y == p.y) {
      m_pDestroyer2->m_HP--;
      return;
    }
  }
}

void GameManager::CheckMap(Position input){
  HitOrMiss = m_pDefender->CheckHit(input);
  if (HitOrMiss == 'H') {
    MinusHP(input);
  }
  m_pAttacker->CheckHit(input, HitOrMiss);
}

string GameManager::DestroyedCheck(Position p){
  if (HitOrMiss == 'M') {
    return "X";
  }else{
    for (size_t i = 0; i < m_pAircraft->GetSize(); i++) {
      if (m_pAircraft->GetPosition()[i].x == p.x && m_pAircraft->GetPosition()[i].y == p.y) {
        if (m_pAircraft->m_HP == 0) {
          return m_pAircraft->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pBattleship->GetSize(); i++) {
      if (m_pBattleship->GetPosition()[i].x == p.x && m_pBattleship->GetPosition()[i].y == p.y) {
        if (m_pBattleship->m_HP == 0) {
          return m_pBattleship->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pCruiser->GetSize(); i++) {
      if (m_pCruiser->GetPosition()[i].x == p.x && m_pCruiser->GetPosition()[i].y == p.y) {
        if (m_pCruiser->m_HP == 0) {
          return m_pCruiser->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pDestroyer1->GetSize(); i++) {
      if (m_pDestroyer1->GetPosition()[i].x == p.x && m_pDestroyer1->GetPosition()[i].y == p.y) {
        if (m_pDestroyer1->m_HP == 0) {
          return m_pDestroyer1->GetName();
        }
      }
    }
    for (size_t i = 0; i < m_pDestroyer2->GetSize(); i++) {
      if (m_pDestroyer2->GetPosition()[i].x == p.x && m_pDestroyer2->GetPosition()[i].y == p.y) {
        if (m_pDestroyer2->m_HP == 0) {
          return m_pDestroyer2->GetName();
        }
      }
    }
    return "X";
  }
}
