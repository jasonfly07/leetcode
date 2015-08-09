#include "stdafx.h"
#include <iostream>
#include <string>

// Check if s and t are anagrams of each other
// s and t consist of lowercase a-z
bool isAnagram(std::string s, std::string t) {
  if (s.size() != t.size()) return false;

  int histo[26];
  for (int i = 0; i < 26; i++) histo[i] = 0;

  for (const char& c : s) histo[c - 97]++;
  for (const char& c : t) histo[c - 97]--;

  for (int i = 0; i < 26; i++) {
    if (histo[i] != 0) return false;
  }

  return true;
}

int main() {

  std::cout << isAnagram("abcd", "dcbe") << std::endl;

  return 0;
}

