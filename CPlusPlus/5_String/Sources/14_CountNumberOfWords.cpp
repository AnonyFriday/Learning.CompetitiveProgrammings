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

int getNumberOfWordsWithoutSpecial(string &sentence) {
  if (sentence.size() == 0) return 0;

  // create a flag for marking a word
  // when go inside a word, set a flag to true, and count + 1
  // when go to the space zone, set a flag to false
  int count = 0;
  bool inWordZone = false;

  for (const char &c : sentence) {
    // in space zone
    if (isspace(c)) {
      inWordZone = false;
    } else if (isalpha(c)) {
      // now currently a character
      // count += 1 and then set in the word zone = true
      if (!inWordZone) {
        count++;
        inWordZone = true;
      }
    }
  }

  return count;
}

int getNumberOfWordsWithSpecial(string &sentence) {
  if (sentence.size() == 0) return 0;

  // a flag to detach if current in word zone
  // when the state changes, then the word is count to 1
  bool isWordZone = false;
  int count = 0;

  // check if in space zone
  for (const char &c : sentence) {
    // if current is space, then continue and set the flag to false
    if (isspace(c)) {
      isWordZone = false;
      continue;
    } else {
      // a character now, and just transition to a word
      if (isWordZone == false) {
        count++;
        isWordZone = true;
      }
    }
  }

  return count++;
}

int main() {
  ios_base::sync_with_stdio(0);

  string s;
  getline(cin, s);

  cout << getNumberOfWordsWithoutSpecial(s) << endl;
  cout << getNumberOfWordsWithSpecial(s);

  return 0;
}