#include <iostream>
#include <ctime>
#include <cstdlib>
int main(int argc, char const *argv[]) {
  srand((unsigned int)time(NULL));
  int row_col = rand()%2;
  std::cout << row_col << '\n';
  return 0;
}
