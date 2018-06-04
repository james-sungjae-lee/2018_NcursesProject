#include "BattleShipApp.hpp"

void BattleShipApp::Play() {
  Init();
  Render();
  Update();
  Destroy();
}

void BattleShipApp::Init() {
  initscr();
  start_color();
  cbreak();
  refresh();

  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);

  m_pStatPane = new StatPane(30, 3, 30, 6);
  m_pInputPane = new InputPane(30, 15, 30, 4);
  m_pGameManager = new GameManager();

  m_pGameManager -> Init();
}

void BattleShipApp::Render() {
  mvprintw(1, 1, "<< Battle Ship Game >>");

  m_pStatPane -> Draw();
  m_pInputPane -> Draw();

  refresh();
}

void BattleShipApp::Destroy() {
  getch();
  endwin();
}

void BattleShipApp::Update() {


}

BattleShipApp::BattleShipApp(){
}

BattleShipApp::~BattleShipApp(){
}
