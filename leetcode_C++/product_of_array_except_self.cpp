#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
  const int N = nums.size();
  std::vector<int> cumProductForward, cumProductBackward;
  cumProductForward.reserve(N);
  cumProductBackward.reserve(N);

  for (int i = 0; i < N; i++) cumProductForward.push_back(1);
  for (int i = 0; i < N; i++) cumProductBackward.push_back(1);

  for (int i = 1; i < N; i++) {
    cumProductForward[i] = cumProductForward[i-1] *  nums[i-1];
  }

  for (int i = N-2; i >= 0; i--) {
    cumProductBackward[i] = cumProductBackward[i+1] * nums[i+1];
  }

  std::vector<int> output;
  output.reserve(N);

  for (int i = 0; i < N; i++){
    output.push_back( cumProductForward[i] * cumProductBackward[i] );
  }

  return output;
}

int main() {

  std::vector<int> v{1,2,3,4};

  std::vector<int> output = productExceptSelf(v);

  for (int i = 0; i < v.size(); i++) {
    std::cout << output[i] << ", ";
  }
  std::cout << std::endl;

  return 0;
}