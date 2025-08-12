#include <bits/stdc++.h>

using namespace std;

/*
        O(logO)
        Instead of O(n), I apply the bit manipulation technique of Bit Manipulation

*/
long long manipulate(long long a, long long b) {
  if (a == 0 || b == 0) return 0;

  long long result = 0;

  // handle negatives, convert all to positives
  // -a x b --> negative
  // -a x -b --> negative
  // a x b --> positive
  // -a x -b --> positive
  bool negative = false;
  if (a < 0) {
    negative = !negative;
    a = -a;
  }

  if (b < 0) {
    negative = !negative;
    b = -b;
  }

  // main logic
  while (b > 0) {
    if (b & 1) {
      result += a;
    };

    a <<= 1;  // shift to left by 1 position, meaning x 2^1
    b >>= 1;  // halve or shift to right by 1 position, meaning / 2^1
  }

  return negative ? -result : result;
}

int main() {
  ios_base::sync_with_stdio(0);

  long long a, b;

  cin >> a >> b;

  cout << manipulate(a, b);

  return 0;
}