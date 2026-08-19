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
        slow way
        2^31 = 2*2*2*2*2*2..... (n times)

        fast way
        2^31 = 2^16 * 2^8 * 2^4 * 2^2 * 2^1

        so by simple make the 31 into the binary form, we calculate the
        value at set bit (1), ignore the (0), then we can get the optimization, which is log(n), since log(31) ~ 5 time based on the lengthg of the binary form

        O: Log(n) looping on the length of binary of p

*/

long long unsigned int exp(int n, int p) {
  if (p == 0) return 1;
  if (p == 1) return n;

  long long unsigned result = 1;
  long long unsigned currentBase = n;

  while (p > 0) {
    if ((p & 1) > 0) {
      result *= currentBase;
    }

    // keep accumulate, untill reaching set bit, then
    // multiple with the result
    currentBase *= currentBase;

    p = p >> 1;  // get the next right-most bit of p
  }

  return result;
}

double expSigned(double n, long int p) {
  if (p == 0) return 1;
  if (p == 1) return n;

  double result = 1.0;
  double currentBase = n;

  // if p is negative, revert it back to positive
  // but the base also equals to 1 / a
  if (p < 0) {
    currentBase = 1.0 / currentBase;
    p = -p;
  }

  // doing the same process
  while (p > 0) {
    if ((p & 1) > 0) {
      result *= currentBase;
    }

    // accumulate till set bit
    currentBase *= currentBase;

    // get the right most bit
    p = p >> 1;
  }

  return result;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  cout << exp(2, 31) << endl;
  cout << expSigned(2, -31) << endl;

  return 0;
}