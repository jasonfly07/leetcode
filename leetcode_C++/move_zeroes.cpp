#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
  int iter1 = 0;
  int iter2 = 0;
  while (iter1 < nums.size()) {
    if (nums[iter1] == 0) {
      iter1++;
    }
    else {
      if (iter1 != iter2) {
        int tmp = nums[iter1];
        nums[iter1] = nums[iter2];
        nums[iter2] = tmp;
      }
      iter1++;
      iter2++;
    }
  }
}

int main() {

  std::vector<int> v{5, 0, 1, 0, 3, 12, 0};

  moveZeroes(v);

  for (int n : v) {
    std::cout << n << std::endl;
  }

  return 0;
}