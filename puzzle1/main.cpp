//
// Puzzle #1: crack the secret code.
//

#include <iostream>
#pragma warning(disable : 4996)

void encode_decode(char *dest, const char *message, const char *key) {
  const char *kp = key;
  while (*message) {
    if (*kp == 0) kp = key;
    *dest++ = *message++ ^ (*kp++ - '0');
  }
  *dest = 0;
}

//"This is a secret message. You can crack it by brute-force methods.",
const char example_message[] = "Ujjw%ot(h!qfgwcs(ddqpebc)(Pnw#gdh'k{`ah$lr'jp!`qqqc*nfsaf$hcs`feq-";
int example_key = 123456789;

// this message also contains the word "secret".
// You can crack the code by trying all the numbers, but a smart cryptologist will get there
// much faster.
const char actual_message[] = "Wimr%dguvbfa!deqi%`njud`lu%wia!rfpb%pdgs`},&Dp!pilz\"ov#`$spk`ovk!gnal.&lw!mr%lcu|#uk!c`lb%wia!nl{(";

// Modify the code below to crack the actual message. How fast can you do it in terms of clock cycles?
// Run in Release mode for better results. Look at the disassembly to get clues about how to optimise it.

// There are two winners. The first finds the solution by any means. The second is the person
// who finds the solution in the fewest cycles in a way that will crack all such codes.

// A naive solution would be something like, loop over all integers, decode the string, search for "secret".
// filter out all the strings that look wrong.

// A smart solution will use the Ascii table to narrow the search down massively!

int main() {
  char key[256];
  sprintf(key, "%d", example_key);

  char tmp[256];
  long long start = __rdtsc();
  encode_decode(tmp, example_message, key);
  long long end = __rdtsc();

  std::cout << tmp << "\n";
  std::cout << end-start << " clocks\n";
}
