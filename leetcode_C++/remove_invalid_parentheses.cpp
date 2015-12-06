#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

bool IsValidParentheses(const std::string& s) {
  int score = 0;
  for (char c : s) {
    switch (c) {
      default:           break;
      case '(': score++; break;
      case ')': score--; break;
    }
    if (score < 0) {
      return false;
    }
  }

  return (score == 0) ? true : false;
}

std::vector<std::string> removeInvalidParentheses(std::string s) {
  std::vector<std::string> output;

  // Remove all leading ')'
  // If startInd is unchanged, return an empty output.
  int startInd = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != ')') {
      startInd = i;
      break;
    }  
  }
  if (startInd == -1) {
    return output;
  }
  s = s.substr(startInd, s.length() - startInd);

  // Remove all trailing '('
  // Likewise, if endInd is unchanged, return an empty output.
  int endInd = -1;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] != '(') {
      endInd = i;
      break;
    }  
  }
  if (endInd == -1) {
    return output;
  }
  s = s.substr(0, endInd + 1);

  // Compute the accumulated score: 
  // '(' = +1, ')' = -1
  int score = 0;
  for (int i = 0; i < s.length(); i++) {
    switch (s[i]) {
      default:
        break;
      case '(':
        score++;
        break;
      case ')':
        score--;
        break;
    } 
  }

  // if score = 0, return s
  if (score == 0) {
    output.push_back(s);
    return output;
  }

  // Set the target to be removed based on the sign of score
  const char tar = score > 0 ? '(' : ')';

  return output;
}

int main() {

  std::string s = ")))(a())()b((()((";
  // std::string s = "((a())b)()c";

  // auto output = removeInvalidParentheses(s);

  // for (auto s : output) {
  //   std::cout << s << std::endl;
  // }

  std::cout << IsValidParentheses(s) << std::endl;


  return 0;
}