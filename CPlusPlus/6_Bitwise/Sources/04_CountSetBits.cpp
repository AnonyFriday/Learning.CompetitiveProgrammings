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

// What is set bits
// - a set bits is the 1s, that's
// - n & 1, if zero meaning not a set bit
// - n & 1, if 1 meaning a set bit
// e.g.
// 			0001 0001 &
//      0000 0001 --> then 0000 0001 > 0 => set bit
//      right shift n
//      0000 1000 &
//      0000 0001 --> then 0000 0000 = 0 => not a set bit

// Big0 Notation
// LogN, since n = 16, binary of it is 2^4
// we only loop 4 time,...
// quite efficient

int countSetBits(int& n) {
  int count = 0;

  while (n > 0) {
    bool isSetBit = (n & 1) > 0 ? 1 : 0;
    if (isSetBit) {
      count += 1;
    }

    n = (n >> 1);
  }

  return count;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int number = 5;  // Binary: 101

  cout << "Original number: " << number << "\n";

  // Call the function
  int result = countSetBits(number);

  cout << "Count of set bits: " << result << "\n";

  // See what happened to the original 'number' variable
  cout << "Number after function call: " << number << "\n";

  cout << "\n";

  int number2 = 10;  // Binary: 1010
  cout << "Original number: " << number2 << "\n";
  int result2 = countSetBits(number2);
  cout << "Count of set bits: " << result2 << "\n";
  cout << "Number after function call: " << number2 << "\n";

  return 0;
}