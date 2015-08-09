#include <iostream>
#include <vector>
#include <cmath>


bool searchMatrix(std::vector<std::vector<int>>& m, int target) {
  // Remove empty matrix
  if (m.size() == 0 || m[0].size() == 0) return false;

  // Set up ranges for row and column
  int r0 = 0; int r1 = m.size() - 1;
  int c0 = 0; int c1 = m[0].size() - 1; 
  
  // Start pruning
  while (c1 >= c0 && r1 >= r0) {
    // Locate the new c0
    // If we can't find c0, it means the target doesn't exist in matrix
    bool c0Found = false;
    for (int c = c0; c <= c1; c++) {
      int minVal = m[r0][c];
      int maxVal = m[r1][c];
      if (target == minVal || target == maxVal) return true;
      if (target > minVal && target < maxVal) {
        c0 = c;
        c0Found = true;
        break;
      }
    }
    if (!c0Found) return false;

    // Locate the new c1
    bool c1Found = false;
    for (int c = c1; c >= 0; c--) {
      int minVal = m[r0][c];
      int maxVal = m[r1][c];
      if (target == minVal || target == maxVal) return true;
      if (target > minVal && target < maxVal) {
        c1 = c;
        c1Found = true;
        break;
      }
    }
    if (!c1Found) return false;

    // Locate the new r0
    bool r0Found = false;
    for (int r = r0; r <= r1; r++) {
      int minVal = m[r][c0];
      int maxVal = m[r][c1];
      if (target == minVal || target == maxVal) return true;
      if (target > minVal && target < maxVal) {
        r0 = r;
        r0Found = true;
        break;
      }
    }
    if (!r0Found) return false;

    // Locate the new r1
    bool r1Found = false;
    for (int r = r1; r >= 0; r--) {
      int minVal = m[r][c0];
      int maxVal = m[r][c1];
      if (target == minVal || target == maxVal) return true;
      if (target > minVal && target < maxVal) {
        r1 = r;
        r1Found = true;
        break;
      }
    }
    if (!r1Found) return false;
  }

  // This line should never be triggered
  return false;
}

int main() {
  std::vector<std::vector<int>> mat = { { 1,  4,  7, 11, 15}, 
                                        { 2,  5,  8, 12, 19}, 
                                        { 3,  6,  9, 16, 22},
                                        {10, 13, 14, 17, 24},
                                        {18, 21, 23, 26, 30}
                                      };
  // std::vector<std::vector<int>> mat = {{1, 3, 5}};
  // std::vector<std::vector<int>> mat = {{1}};


  std::cout << searchMatrix(mat, 20) << std::endl;
  return 0;
}