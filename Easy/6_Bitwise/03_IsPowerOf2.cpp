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

// 1 number is power of two if
bool isPowerOfTwo(const int& a) {
  // 8 = 2^3 = 0000 1000
  // 8 - 1 = 7 = 0000 0111
  // 8 & 7 == 0 always
  // N & (N - 1) == 0, then it's power of two
  return (a & (a - 1)) == 0;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  cout << isPowerOfTwo(8) << endl;
  cout << isPowerOfTwo(10) << endl;
  cout << isPowerOfTwo(7) << endl;
  cout << isPowerOfTwo(2) << endl;
  cout << isPowerOfTwo(16) << endl;

  return 0;
}