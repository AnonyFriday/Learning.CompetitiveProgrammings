#include <bits/stdc++.h>

// #include <algorithm>
// #include <cassert>
// #include <climits>
// #include <cmath>
// #include <cstring>
// #include <iostream>
// #include <list>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <unordered_map>
// #include <vector>
//
using namespace std;

const double E = 1e-8;
const double PI = acos(-1);

// Using seen array
bool isPresentAllCharacters(const string& s) {
  int seen[26] = {0};

  for (int i = 0; i < s.size(); i++) {
    // check if it's the alphabet, then set the flag on the seen
    if (isalpha(s[i])) {
      int idx = tolower(s[i]) - 'a';
      seen[idx] = 1;
    }
  }

  // if any element is zero, meaning not having a full entire alphabet
  for (const int& i : seen) {
    if (i == 0) return false;
  }

  return true;
}

/*
        Having a mask: 0b00000000000000000000000 (26 of 0s)
        if any character represents, transform its into index 0
*/

bool isPresentAllCharactersUsingBit(const string& s) {
  if (s.size() == 0 || s.size() <= 26) return false;

  int mask = 0;  // all zeros
  for (char c : s) {
    // check if it's alpha
    if (isalpha(c)) {
      /*

              First: compute 1 << bit
              Example: if bit = 3, then 1 << 3 = 8 (binary 1000).
              Then: do mask |= (that value)
              Equivalent to mask = mask | (1 << bit).
              --> then become 00000100000.... 1 represntes for index in the alphabet

      */

      int bit = tolower(c) - 'a';
      mask |= (1 << bit);
    }
  }

  return mask == ((1 << 26) - 1);
}

int main() {
  ios_base::sync_with_stdio(0);

  string a;
  getline(cin, a);

  std::cout << isPresentAllCharacters(a) << endl;
  std::cout << isPresentAllCharactersUsingBit(a) << endl;

  return 0;
}