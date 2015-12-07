#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

// A simple utility that checks whether s is a valid expression
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

// BFS: search level by level. Start with level 0 (don't remove any parenthesis)
// if invalid, produce all possible strings in level 1 (remove 1 parenthesis)
// if still no valid strings, go down to level 2 (remove 2 parentheses), so on so forth
std::vector<std::string> removeInvalidParentheses(std::string s) {
  std::vector<std::string> output;

  // stores all solutions
  std::unordered_set<std::string> found;

  // store all candidates in the current level 
  std::unordered_set<std::string> candidates;
  candidates.insert(s);

  // BFS
  while (!candidates.empty()) {
    // Make a copy of the candidate list
    std::unordered_set<std::string> candidatesCopy(candidates);
    candidates.clear();

    // iterate through all candidates in current level
    for (auto& currStr : candidatesCopy) {

      // If the current string is valid, store it in found
      if (IsValidParentheses(currStr)) {
        found.insert(currStr);
      }
      // If invalid, take away one parenthesis and add it to the candidate list
      // Note that this step is not needed if we already found some solutions in 
      // the current level
      else {
        if (!found.empty()) continue;
        for (int k = 0; k < currStr.length(); k++) {
          if (currStr[k] == '(' || currStr[k] == ')') {
            std::string newStr = currStr.substr(0, k) + currStr.substr(k + 1);
            if (candidates.count(newStr) == 0) {
              candidates.insert(newStr);
            }
          }
        }
      }
    }

    if (found.size() > 0) {
      break;
    }
  }

  // Move all solutions back to the output vector
  for (const std::string& s : found) {
    output.push_back(s);
  }

  return output;
}

int main() {

  std::string s = ")))(a())()b((()((";
  // std::string s = "(a)())()";
  // std::string s = ")(";

  auto output = removeInvalidParentheses(s);

  for (auto s : output) {
    std::cout << s << std::endl;
  }


  return 0;
}