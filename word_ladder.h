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

// TODO(students): Add some stuff here
void findPaths(const std::string &start, const std::string &end);

bool inPath(const std::vector<std::string> &path, const std::string &node);

void printPath(const std::vector<std::string> &path);

bool inLexicon(const std::unordered_set<std::string> &lexicon,
               const std::string &word);

std::vector<std::string> &get_neighbours(const std::string &word);

void preprocess(const std::unordered_set<std::string> &lexicon,
                const std::string &word);

#endif
