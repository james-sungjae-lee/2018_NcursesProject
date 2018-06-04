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

  for (size_t i = 0; i < m_pAircraft->GetSize(); i++) {
    m_pAircraft->m_Position[i].x = i;
    m_pAircraft->m_Position[i].y = 1;
  }

  m_pDefender->setShip(m_pAircraft);

}
