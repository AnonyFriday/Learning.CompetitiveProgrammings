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

int isSorted(char *c, int size, bool isAscending = true) {
  if (size == 0) return 0;
  if (size == 1) return 1;

  for (int i = 1; i < size; i++) {
    if (c[i - 1] == c[i]) continue;

    if (isAscending && c[i - 1] > c[i]) {
      return 0;
    } else if (!isAscending && c[i - 1] < c[i]) {
      return 0;
    }
  }

  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;
  cin.ignore();

  char str[N];
  cin.getline(str, N, '\n');

  cout << isSorted(str, N, true);

  return 0;
}