#include "BattleShipApp.hpp"

void BattleShipApp::Play(){
  Init();
  Render();
  while (m_pGameManager->GameOver() == false) {
    m_pStatPane->ShipDestroyed(DestroyedShip);
    Update();
    if (input.x == 100) {
      break;
    }
  }
  m_pStatPane->ShipDestroyed(DestroyedShip);
  m_pStatPane->GameWin(turn);
  Destroy();
}

void BattleShipApp::PlayAI(){
  Init();
  Render();
  while (m_pGameManager->GameOver() == false) {
    m_pStatPane->ShipDestroyed(DestroyedShip);
    UpdateAI();
    getch();
  }
  m_pStatPane->ShipDestroyed(DestroyedShip);
  m_pStatPane->GameWin(turn);
  Destroy();
}

void BattleShipApp::Init(){
  srand((unsigned int)time(NULL));
  initscr();
  start_color();
  cbreak();
  refresh();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);

  m_pStatPane = new StatPane(30, 3, 30, 8);
  m_pInputPane = new InputPane(30, 15, 30, 4);
  m_pGameManager = new GameManager();
  turn = 0;
  DestroyedShip = "X";

  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      AIAttackMap[i][j] = 0;
    }
  }
}

void BattleShipApp::Render(){
  mvprintw(1, 1, "<< Battle Ship Game >>");
  m_pStatPane -> Draw();
  m_pInputPane -> Draw();
  m_pGameManager -> Init();
  refresh();
}

void BattleShipApp::Destroy(){
  getch();
  endwin();
}

void BattleShipApp::Update(){
  turn ++;
  m_pStatPane->DrawTurn(turn);
  input = m_pInputPane->GetInput();
  m_pGameManager->input = input;
  m_pGameManager->CheckMap(input);
  DestroyedShip = m_pGameManager->DestroyedCheck(input);
}

Position BattleShipApp::GetInputAI(){
  int x, y;
  Position returnPosition;
  while (true) {
    x = rand()%8;
    y = rand()%8;
    if (AIAttackMap[x][y] == 1) {
      continue;
    }else{
      AIAttackMap[x][y] = 1;
      returnPosition.x = x;
      returnPosition.y = y;
      return returnPosition;
    }
  }
}

void BattleShipApp::UpdateAI(){
  turn ++;
  m_pStatPane->DrawTurn(turn);
  input = GetInputAI();
  m_pGameManager->input = input;
  m_pGameManager->CheckMap(input);
  DestroyedShip = m_pGameManager->DestroyedCheck(input);
}

BattleShipApp::BattleShipApp(){}
BattleShipApp::~BattleShipApp(){}
