// Copyright [2019] Kai Xiang Yong z5175681
// COMP6771 Assignment 1 Word Ladder
#include "assignments/wl/word_ladder.h"

// Global Variable
// A 'dict' to store neighbours of visited word
std::unordered_map<std::string, std::vector<std::string>> visited;
std::unordered_set<std::string> new_lexicon;

// TODO(students): Add your stuff here
void findPaths(const std::string &start, const std::string &end) {
  // Set up for BFS
  std::queue<std::vector<std::string>> open;

  // Extra
  std::string curr_word = start;
  std::vector<std::string> curr_path;
  curr_path.push_back(curr_word);
  // Set Path Length Limit
  std::size_t limit = 15;

  // Enqueue start
  open.push(curr_path);

  while (!open.empty()) {
    curr_path = open.front();
    curr_word = curr_path.back();
    open.pop();

    if (curr_path.size() >= limit) {
      break;
    }

    if (curr_word == end) {
      limit = curr_path.size();
      continue;
    } else {
      // Add all neighbours if not visited in same path
      for (const auto &word : get_neighbours(curr_word)) {
        if (inPath(curr_path, word)) {
          continue;
        }
        std::vector<std::string> new_path(curr_path);
        new_path.push_back(word);
        new_lexicon.insert(word);
        if (word == end) {
          if (limit != new_path.size()) {
            std::cout << "Found ladder: ";
            limit = new_path.size();
          }
          printPath(new_path);
          continue;
        } else {
          open.push(new_path);
        }
      }
    }
  }
}

bool inPath(const std::vector<std::string> &path, const std::string &node) {
  for (const auto &word : path) {
    if (word == node) {
      return true;
    }
  }
  return false;
}

void printPath(const std::vector<std::string> &path) {
  for (const auto &node : path) {
    std::cout << node << " ";
  }
  std::cout << "\n";
}

bool inLexicon(const std::unordered_set<std::string> &lexicon,
               const std::string &word) {
  return lexicon.end() != lexicon.find(word);
}

std::vector<std::string> &get_neighbours(const std::string &word) {
  if (visited.find(word) != visited.end()) {
    return visited[word];
  } else {
    std::vector<std::string> neighbours;
    for (std::size_t i = 0; i < word.length(); i++) {
      for (char a = 'a'; a <= 'z'; a++) {
        const std::string new_word = word.substr(0, i) + a + word.substr(i + 1);
        if (inLexicon(new_lexicon, new_word)) {
          neighbours.push_back(new_word);
          new_lexicon.erase(new_word);
        }
      }
    }
    return visited[word] = neighbours;
  }
}

void preprocess(const std::unordered_set<std::string> &lexicon,
                const std::string &word) {
  for (const auto &item : lexicon) {
    if (item.length() == word.length()) {
      new_lexicon.insert(item);
    }
  }
}
