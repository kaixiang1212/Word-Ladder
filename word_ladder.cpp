// Copyright [2019] Kai Xiang Yong z5175681
// COMP6771 Assignment 1 Word Ladder
#include "assignments/wl/word_ladder.h"

//----------------- Global Variable-------------------
/**
 * A 'dict' to store neighbours of visited word
 *                     Word      List of its neighbours
 */
std::unordered_map<std::string, WordList> visited;

/**
 *Store our set of pre-processed lexicon
 */
std::unordered_set<std::string> new_lexicon;

//----------------- Fuctions Starts -------------------
/**
 * Function to find a list of path
 * @param start Word to start with
 * @param end Word to end with
 * @return all The shortest path
 */
std::vector<WordList> findPaths(const std::unordered_set<std::string> &lexicon,
                                const std::string &start,
                                const std::string &end) {
  std::vector<WordList> solution;

  if (!isValidInput(start, end)) {
    std::cout << "No ladder found."
              << "\n";
    return solution;
  }

  preprocess(lexicon, start);
  // Set up for BFS
  std::queue<WordList> open;

  // Extra
  std::string curr_word = start;
  WordList curr_path;
  curr_path.push_back(curr_word);
  // Set Path Length Limit
  std::size_t limit = 40;

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
        WordList new_path(curr_path);
        new_path.push_back(word);
        new_lexicon.insert(word);
        if (word == end) {
          if (limit != new_path.size()) {
            std::cout << "Found ladder: ";
            limit = new_path.size();
          }
          solution.push_back(new_path);
          printPath(new_path);
          continue;
        } else {
          open.push(new_path);
        }
      }
    }
  }
  return solution;
}

/**
 * Check whether a string is in a word list
 * @param path List of words
 * @param string The word to search for
 * @return True if given string is in the list false otherwise
 */
bool inPath(const WordList &path, const std::string &string) {
  for (const auto &word : path) {
    if (word == string) {
      return true;
    }
  }
  return false;
}

/**
 * Print a list of words given a path/list of words
 * @param path List of words to print
 */
void printPath(const WordList &path) {
  for (const auto &node : path) {
    std::cout << node << " ";
  }
  std::cout << "\n";
}

/**
 * Check whether a word is in the lexicon
 * @param word Word to check
 * @return  True if the given string is in lexicon
 */
bool inLexicon(const std::string &string) {
  return new_lexicon.end() != new_lexicon.find(string);
}

/**
 * Take a word and return its neighbours
 * @param word The word to search for its neighbour
 * @return All its neighbours in a list
 */
WordList &get_neighbours(const std::string &word) {
  if (visited.find(word) != visited.end()) {
    return visited[word];
  } else {
    WordList neighbours;
    for (std::size_t i = 0; i < word.length(); i++) {
      for (char a = 'a'; a <= 'z'; a++) {
        const std::string new_word = word.substr(0, i) + a + word.substr(i + 1);
        if (inLexicon(new_word)) {
          neighbours.push_back(new_word);
          new_lexicon.erase(new_word);
        }
      }
    }
    return visited[word] = neighbours;
  }
}

/**
 * Preprocess lexicon to avoid any redundant check
 * @param lexicon The Set of Big Lexicon
 * @param word  A reduced size lexicon
 */
void preprocess(const std::unordered_set<std::string> &lexicon,
                const std::string &word) {
  for (const auto &item : lexicon) {
    if (item.length() == word.length()) {
      new_lexicon.insert(item);
    }
  }
}
/**
 * Check if given inputs are valid
 * @param start Word 1 to check
 * @param end Word 2 to check
 * @return True if inputs are valid
 */
bool isValidInput(const std::string &start, const std::string &end) {
  if (start.length() != end.length()) {
    return false;
  }
  for (std::size_t i = 0; i < start.length(); i++) {
    if (start.at(i) < 'a' || start.at(i) > 'z' || end.at(i) < 'a' ||
        end.at(i) > 'z') {
      return false;
    }
  }
  return true;
}
