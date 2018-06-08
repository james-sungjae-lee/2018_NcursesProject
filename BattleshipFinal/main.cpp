// C++ BattleShip Project
// 작성일자 2018-05-25
// 학번 : 20132651 이름 : 이성재

#include "BattleShipApp.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main(){
  std::vector<int> AIturns;
  int average = 0;

  for (size_t i = 0; i < 10; i++) {
    BattleShipApp battleShip;
    battleShip.PlayAI();
    AIturns.push_back(battleShip.lastTurn);
  }

  sort(AIturns.begin(), AIturns.end());
  for (size_t i = 0; i < AIturns.size(); i++) {
    average += AIturns[i];
  }

  average = average / AIturns.size();
  std::cout << "Minimum Turn : " << AIturns[0]<< '\n';
  std::cout << "Maximum Turn : " << AIturns.back()<< '\n';
  std::cout << "Average Turn : " << average << '\n';

  return 0;
}
