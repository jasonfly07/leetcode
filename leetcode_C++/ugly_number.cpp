#include <iostream>
#include <cmath>

bool isUgly(int num) {
  if (num == 1) return true;
  if (num == 0) return false;

  double numd = (double)num;

  while (true) {
    numd /= 2;
    if (floor(numd) != numd) {
      numd *= 2;
      break;
    }
  }

  while (true) {
    numd /= 3;
    if (floor(numd) != numd) {
      numd *= 3;
      break;
    }
  }

  while (true) {
    numd /= 5;
    if (floor(numd) != numd) {
      numd *= 5;
      break;
    }
  }

  return (numd == 1) ? true : false;
}

int main() {

  std::cout << isUgly(2147483647) << std::endl;

  return 0;
}