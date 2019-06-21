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
  if (start.length() != end.length()) {
    std::cout << "No ladder found."
              << "\n";
    return 1;
  }
  for (std::size_t i = 0; i < start.length(); i++) {
    if (start.at(i) < 'a' || start.at(i) > 'z' || end.at(i) < 'a' ||
        end.at(i) > 'z') {
      std::cout << "No ladder found."
                << "\n";
      return 1;
    }
  }
  preprocess(lexicon, start);

  findPaths(start, end);
  return 0;
}
