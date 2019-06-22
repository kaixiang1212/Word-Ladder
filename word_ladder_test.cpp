// Copyright [2019] Kai Xiang Yong z5175681
// COMP6771 Assignment 1 Word Ladder
/*
  I have tested many possible invalid input such that my
  program would produce the right output so that it behave
  as it should.

*/
#define CATCH_CONFIG_MAIN
#include "assignments/wl/lexicon.h"
#include "assignments/wl/word_ladder.h"
#include "catch.h"

auto lexicon = GetLexicon("assignments/wl/words.txt");
std::vector<WordList> empty = {};

TEST_CASE("Normal test 'con' and 'cat'") {
  std::vector<WordList> path = {{"con", "can", "cat"}, {"con", "cot", "cat"}};
  REQUIRE(findPaths(lexicon, "con", "cat") == path);
}

TEST_CASE("Normal test on 'work' and 'play'") {
  std::vector<WordList> path = {
      {"work", "fork", "form", "foam", "flam", "flay", "play"},
      {"work", "pork", "perk", "peak", "pean", "plan", "play"},
      {"work", "pork", "perk", "peak", "peat", "plat", "play"},
      {"work", "pork", "perk", "pert", "peat", "plat", "play"},
      {"work", "pork", "porn", "pirn", "pian", "plan", "play"},
      {"work", "pork", "port", "pert", "peat", "plat", "play"},
      {"work", "word", "wood", "pood", "plod", "ploy", "play"},
      {"work", "worm", "form", "foam", "flam", "flay", "play"},
      {"work", "worn", "porn", "pirn", "pian", "plan", "play"},
      {"work", "wort", "bort", "boat", "blat", "plat", "play"},
      {"work", "wort", "port", "pert", "peat", "plat", "play"},
      {"work", "wort", "wert", "pert", "peat", "plat", "play"},
  };
  REQUIRE(findPaths(lexicon, "work", "play") == path);
}

TEST_CASE("No input") {
  REQUIRE(findPaths(lexicon, "", "cat") == empty);
  REQUIRE(findPaths(lexicon, "cat", "") == empty);
  REQUIRE(findPaths(lexicon, "", "") == empty);
}

TEST_CASE("Input has auto space at back") {
  REQUIRE(findPaths(lexicon, "cat ", "con") == empty);
  REQUIRE(findPaths(lexicon, "cat", "con ") == empty);
  REQUIRE(findPaths(lexicon, "cat ", "con ") == empty);
}

TEST_CASE("Input is a space") {
  REQUIRE(findPaths(lexicon, " ", "cat") == empty);
  REQUIRE(findPaths(lexicon, "cat", " ") == empty);
  REQUIRE(findPaths(lexicon, " ", " ") == empty);
}

TEST_CASE("Capital Letters") {
  REQUIRE(findPaths(lexicon, "Work", "play") == empty);
  REQUIRE(findPaths(lexicon, "work", "Play") == empty);
  REQUIRE(findPaths(lexicon, "Work", "Play") == empty);
}

TEST_CASE("Numeric"){
  REQUIRE(findPaths(lexicon, "w0rk", "play") == empty);
}