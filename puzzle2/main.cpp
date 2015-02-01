////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2015
//
// Puzzle #2: Bulls and Cows
//

//
// In the game Bulls and Cows, you must guess a four digit number.
//
// On every guess, the other player marks you with a "bull" for each
// number that is correct in the correct place and a "cow" for each number
// that is correct but in the wrong place.
//
// For example, if the hidden number is 1234 then:
//
// 1234 scores 4 bulls - a win.
// 5678 scores nothing
// 1243 scores 2 bulls and two cows.
// 8123 scores 3 cows
//
// if the number is 2222
// 1234 scores 1 bull
//
// if the number is 1234
// 8822 scores 1 cow

#include <utility>
#include <iostream>
#include <cassert>

//
// this is an example scoring function with several bits missing.
//
std::pair<int, int> score(int guess, int answer) {
  // here is an expression that gets the digits of the answer.
  // it is missing the upper two digits, can you complete it?
  int ad[] = { 0, 0, answer / 10 % 10, answer % 10 };
  int gd[] = { 0, 0, guess / 10 % 10, guess % 10 };

  // here is a loop that finds the bulls.
  int bulls = 0, cows = 0;
  for (int i = 0; i != 4; ++i) {
    if (gd[i] == ad[i]) {
      bulls++;
    }
  }

  // can you write a loop to find the cows?
  // how can we prevent it from counting bulls or counting
  // cows twice (eg. 1234 vs 0022 or 2234 vs 0002)

  return std::make_pair(bulls, cows);
}

// here is an example game with one move to make.
// can you tell what is the answer just from these scores?
static const int game[][3] = {
  {1234, 1, 1},
  {5678, 0, 1},
  {9012, 0, 2},
  {5566, 0, 0},
  {7788, 1, 0},
  {1180, 1, 1},
  {2281, 1, 1},
  {1849, 1, 0},
};

int main() {
  // test the scoring function
  // this will fail... you must fix it by fixing the scoring function.
  assert(score(1234, 1234) == std::make_pair(4, 0));
  assert(score(5678, 1234) == std::make_pair(0, 0));
  assert(score(1243, 1234) == std::make_pair(2, 2));
  assert(score(8123, 1234) == std::make_pair(0, 3));
  assert(score(1234, 2222) == std::make_pair(1, 0));
  assert(score(8822, 1234) == std::make_pair(0, 1));

  // write a loop here that completes the example game
}
