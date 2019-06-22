// Copyright [2019] Kai Xiang Yong z5175681
// COMP6771 Assignment 1 Word Ladder
#ifndef ASSIGNMENTS_WL_WORD_LADDER_H_
#define ASSIGNMENTS_WL_WORD_LADDER_H_
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using WordList = std::vector<std::string>;

std::vector<WordList> findPaths(const std::unordered_set<std::string> &lexicon,
                                const std::string &start,
                                const std::string &end);
bool inPath(const WordList &path, const std::string &string);
void printPath(const WordList &path);
bool inLexicon(const std::string &string);
WordList &get_neighbours(const std::string &word);
void preprocess(const std::unordered_set<std::string> &lexicon,
                const std::string &word);
bool isValidInput(const std::string &start, const std::string &end);

#endif // _HOME_KXY_DOCUMENTS_ASS1_ASSIGNMENTS_WL_WORD_LADDER_H_
