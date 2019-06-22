// Copyright [2019] Kai Xiang Yong z5175681
// COMP6771 Assignment 1 Word Ladder
#include <iostream>

#include "assignments/wl/lexicon.h"
#include "assignments/wl/word_ladder.h"

int main() {
  auto lexicon = GetLexicon("assignments/wl/words.txt");

  // TODO(students): Replace this with your code
  std::string start, end;
  std::cout << "Enter start word (RETURN to quit): ";
  getline(std::cin, start);
  if (start == "")
    return 0;
  std::cout << "Enter destination word: ";
  getline(std::cin, end);

  findPaths(lexicon, start, end);
  return 0;
}
