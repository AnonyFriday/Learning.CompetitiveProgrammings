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

void inputArray(vector<int>& arr) {
  int i = 0;
  while (i < arr.size()) {
    cin >> arr[i];
    i++;
  }
}

// = DO HERE ========================

// space complexity: O(N)
// time complexity: O(N)
bool isSorted(vector<int>& arr, int n) {
  if (n == 1 || n == 0) return 1;

  // check if arr[n - 1] > arr[n - 2] or not
  // if yes, move on arr[n - 2] and arr[n - 3]

  return (arr[n - 1] >= arr[n - 2]) &&
         isSorted(arr, n - 1);
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> arr(n);

  inputArray(arr);

  cout << isSorted(arr, n);

  return 0;
}