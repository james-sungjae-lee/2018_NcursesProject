#include "BattleShipApp.h"

void BattleShipApp::Play(){
  Init();
  Render();
  while (m_pGameManager->GameOver() == false) {
    Update();
    if (gameQuit == true) {
      break;
    }
  }
  m_pStatPane->GameWin(turn);
  Destroy();
}

void BattleShipApp::SelectMode(){
  mvprintw(1, 1, "<< Battle Ship Game >>");
  mvprintw(2, 1, "<< Select Game Mode >>");
  mvprintw(3, 1, "<< 1: Input / 2: AI >>");
  mvprintw(4, 1, "Select Game Mode : ");
  // mvscanw(4, 20, "%d", select);
  // if (select == 1) {
  //   myGameMode = PLAY_INPUT;
  // }else if (select == 2) {
  //   myGameMode = PLAY_FOLLOW_AI;
  // }else{
  //   myGameMode = PLAY_INPUT;
  // }
  getch();
}

void BattleShipApp::Init(){
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
  gameQuit = false;
}

void BattleShipApp::Render(){
  mvprintw(1, 1, "<< Battle Ship Game >>");

  m_pStatPane -> Draw();
  m_pInputPane -> Draw();
  m_pGameManager -> Init();
  refresh();
}

void BattleShipApp::Update(){
  turn ++;
  m_pStatPane->DrawTurn(turn);
  input = m_pInputPane->GetInput();
  if (input.x == 100) {
    gameQuit = true;
    return;
  }
  m_pGameManager->input = input;
  m_pGameManager->CheckMap(input);
  DestroyedShip = m_pGameManager->DestroyedCheck(input);
}

void BattleShipApp::Destroy(){
  getch();
  endwin();
}

BattleShipApp::BattleShipApp(){}
BattleShipApp::~BattleShipApp(){}
