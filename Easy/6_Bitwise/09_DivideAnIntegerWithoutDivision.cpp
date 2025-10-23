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
//`
using namespace std;

const double E = 1e-8;
const double PI = acos(-1);

// Divide an integer using bit manipulation
// 10 / 4 = 10 * 4^-1
// a / b = a / 2^n = a >> n
int divide(int X, int Y) {
  // 0000 0100
  // for b = 2^k, find the largest k
  // we gonna find the largest 2^k, which mean k is largest
  if (Y == 0) return -1;
  if (X == 0) return 0;

  bool isNegative = (X < 0) || (Y < 0);

  int quotient = 0;

  while (Y <= X) {
    X -= Y;
    quotient++;
  }
  return isNegative ? -quotient : quotient;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  cout << divide(7, 3) << endl;

  return 0;
}