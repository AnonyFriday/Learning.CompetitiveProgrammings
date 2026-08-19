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

/*

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

*/

int romanToInt(const string& str) {
  std::unordered_map<char, int> romans = {
      {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

  int N = str.length();

  // empty string
  if (N == 0) return 0;

  // only 1
  if (N == 1) return romans[str[0]];

  unsigned long long int result = 0;

  // start from back
  // if curr > prev, then total += (curr - prev), set curr = prev - 1
  // if curr < prev, then total += curr, curr--

  int curr = N - 1;

  while (curr >= 0) {
    char cCurr = str[curr];

    // 0     1     2   3
    // prev  crr

    if (curr - 1 >= 0) {
      int prev = curr - 1;
      char cPrev = str[prev];
      if (romans[cCurr] > romans[cPrev]) {
        result += (romans[cCurr] - romans[cPrev]);
        curr -= 2;
      } else {
        result += romans[cCurr];
        curr--;
      }

    } else {
      result += romans[cCurr];
      curr--;
    }
  }
  return result;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  std::cout << romanToInt("LVIII") << endl;
  std::cout << romanToInt("MCMXCIV") << endl;

  return 0;
}