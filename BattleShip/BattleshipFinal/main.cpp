// C++ BattleShip Project
// 작성일자 2018-06-08
// 학번 : 20132651 이름 : 이성재

#include "BattleShipApp.h"
#include <vector>
#include <iostream>
#include <algorithm>

int main(){
  std::vector<int> AIturns;
  int average = 0;
  int playType;

  std::cout << "Play Input : 1 // Play AI : 2" << '\n';
  std::cin >> playType;

  if (playType == 1) {
    BattleShipApp battleShip;
    battleShip.Play();
  }else{
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
  }
  return 0;
}
