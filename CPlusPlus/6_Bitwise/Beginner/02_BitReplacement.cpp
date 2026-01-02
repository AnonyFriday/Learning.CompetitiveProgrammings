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

void clearBitsInRange(int &n, int i, int j) {
  int A = (-1 << (j + 1));
  int B = (1 << i) - 1;
  int mask = A | B;

  n = n & mask;
}

// replace m in n
void updateBitsInRange(int &n, int i, int j, int m) {
  // clear the range first
  // then set the range with |

  // 1111 1010
  // i = 1, j = 3 --> 1111 0000
  clearBitsInRange(n, i, j);

  int mask = m << i;
  n = n | mask;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n = 10;

  cout << "n: " << n << " (0000 1010)" << endl;

  // 0000 0001 -> 0000 0010
  // shift m to left ith position
  updateBitsInRange(n, 1, 3, 1);

  cout << "Changed n: " << n;

  return 0;
}