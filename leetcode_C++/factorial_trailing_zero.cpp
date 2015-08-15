#include <iostream>
#include <vector>
#include <cmath>

int trailingZeroes(int n) {

  int count5 = 0;
  int k = 5;
  while (k <= n) {
    int q = n / k;
    count5 += q;
    
    // Prevent k from overflow with n is too large
    if (q < 5) break;

    k *= 5;
  }

  return count5;
}

int main() {

  const int input = 2147483647;
  // std::cout << input / 125 << std::endl;
  std::cout << trailingZeroes(input) << std::endl;

  return 0;
}