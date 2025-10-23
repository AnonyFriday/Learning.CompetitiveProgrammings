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
Slow
        2^2 = 2 * 2;
        16 ^ 2 = 16 * 16
                                O: n times

Fazt
15^2 = 15 * (8 + 4 + 2 + 1)
     = 15 * 8 + 15 * 4 + 15 * 2 + 15 * 1

So O: is logn due to we destructure into binary 1s representation
keep get the right most bit, if = 1 then last bit * 2^p, and p *= 2

*/
int square(int n) {
  if (n == 0) return 1;

  int p = 1;  // 2^0
  int result = 0;
  int tempN = n;

  while (n > 0) {
    // if last bit is 1
    if ((n & 1) > 0) {
      result += p * tempN;
    }

    p *= 2;      // accumulate the 2^p
    n = n >> 1;  // next last bit
  }

  return result;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  cout << square(5) << endl;
  cout << square(10) << endl;
  cout << square(100) << endl;

  return 0;
}