#include "BattleShipApp.h"

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
  }
  m_pStatPane->ShipDestroyed(DestroyedShip);
  m_pStatPane->GameWin(turn);
  lastTurn = turn;
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
  Position pushPosition;

  for (size_t x = 0; x < 8; x++) {
    for (size_t y = 0; y < 8; y++) {
      AIAttackMap[x][y] = m_pGameManager->m_pAttacker->m_pMap->m_mapData[x][y];
      if (AIAttackMap[x][y] == 'H') {

        if (x < 7 && AIAttackMap[x+1][y] == '-') {
          pushPosition.x = x + 1;
          pushPosition.y = y;
          nextAttack.push_back(pushPosition);
        }
        if (y < 7 && AIAttackMap[x][y+1] == '-') {
          pushPosition.x = x;
          pushPosition.y = y + 1;
          nextAttack.push_back(pushPosition);
        }

        if (0 < x && AIAttackMap[x-1][y] == '-') {
          pushPosition.x = x - 1;
          pushPosition.y = y;
          nextAttack.push_back(pushPosition);
        }

        if (0 < y && AIAttackMap[x][y-1] == '-') {
          pushPosition.x = x;
          pushPosition.y = y - 1;
          nextAttack.push_back(pushPosition);
        }
      }
    }
  }

  while (true) {

    x = rand()%8;
    y = rand()%8;

    while (true) {
      if (!nextAttack.empty()) {
        returnPosition = nextAttack.back();
        if (AIAttackMap[returnPosition.x][returnPosition.y] == '-') {
          nextAttack.pop_back();
          return returnPosition;
        }else{
          nextAttack.pop_back();
          continue;
        }
      }else{
        break;
      }
    }

    if (AIAttackMap[x][y] == '-') {
      returnPosition.x = x;
      returnPosition.y = y;
      return returnPosition;
    }else{
      continue;
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
