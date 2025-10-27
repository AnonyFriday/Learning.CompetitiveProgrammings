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

// 0 1 1 2 3 5 8
// currently think of 1-base number
int fibonacii(int n) {
  if (n == 1) return 0;
  if (n == 2) return 1;

  int ans = fibonacii(n - 1) + fibonacii(n - 2);
  return ans;
}

// using traditional loop, without using stack
int fibonaciiTrad(int n) {
  if (n == 1) return 0;
  if (n == 2) return 1;

  int i = 0;
  int j = 1;
  int result;
  int cnt = 3;

  while (cnt <= n) {
    result = i + j;
    i = j;
    j = result;
    cnt++;
  }

  return result;
}

int fibonaciiTradBase0(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  int i = 0;
  int j = 1;
  int result;
  int cnt = 2;

  while (cnt <= n) {
    result = i + j;
    i = j;
    j = result;
    cnt++;
  }

  return result;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n;
  cin >> n;
  cout << fibonacii(n) << endl;
  cout << fibonaciiTrad(n) << endl;
  cout << fibonaciiTradBase0(n) << endl;

  return 0;
}