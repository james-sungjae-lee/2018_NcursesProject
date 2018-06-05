#include "GameManager.hpp"

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
  return m_pAircraft->Destroyed && m_pBattleship->Destroyed && m_pCruiser->Destroyed && m_pDestroyer1->Destroyed && m_pDestroyer2->Destroyed;
}

void GameManager::CheckMap(string input){
  char HitOrMiss;
  HitOrMiss = m_pDefender->CheckHit(input);
  m_pAttacker->CheckHit(input, HitOrMiss);
}
