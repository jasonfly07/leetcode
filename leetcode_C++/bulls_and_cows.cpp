#include <iostream>
#include <string>
#include <vector>

void StringToNumbers(const std::string& str, std::vector<int>& output) {
  output.clear();
  for (const char c : str) {
    output.push_back(c - 48);
  }
}

std::string getHint(const std::string& secret, const std::string& guess) {
  // Initilaize the histograms
  std::vector<int> histoSecret(10, 0);
  std::vector<int> histoGuess(10, 0);
  int countA = 0;
  int countB = 0;

  // Convert strings to vectors of numbers
  std::vector<int> secretVec, guessVec;
  StringToNumbers(secret, secretVec);
  StringToNumbers(guess,  guessVec);

  // Iterate through the vectors, construct the histogram, and count A
  for (int i = 0; i < secretVec.size(); i++) {
    if(secretVec[i] == guessVec[i]) countA++;
    else {
      histoSecret[secretVec[i]]++;
      histoGuess[guessVec[i]]++;
    }
  }

  // Iterate through the histograms and count B
  for (int i = 0; i < 10; i++) {
    countB += std::min(histoSecret[i], histoGuess[i]);
  }

  return std::to_string(countA) + "A" + std::to_string(countB) + "B";
}

int main(){
  std::string secret = "1107";
  std::string guess  = "0010";

  std::cout << getHint(secret, guess) << std::endl;

  return 0;
}