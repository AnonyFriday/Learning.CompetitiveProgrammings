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

int sumOfTotalFormular(int n) {
  if (n == 0) return 0;

  return n * (n + 1) / 2;
}

// base: stop at the last element
// this is an example of non-tail recursion where the state of the sum have to be conducted after the function call end
int sumOfDigits(int n) {
  if (n == 0) return n;

  // get the digit
  int digit = n % 10;
  return digit + sumOfDigits(n / 10);
}

// 555                 0
// 1. 55, sum = 5      5
// 2. 5, sum = 10      10
// 3. 0, sum = 15      15
// this is an example of tail recursion
// - where recursion carries away the state (varaible sum)
int sumOfDigitsDesc(int n, int sum = 0) {
  if (n == 0) return sum;

  return sumOfDigitsDesc(n / 10, sum + (n % 10));
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n;
  cin >> n;

  cout << sumOfTotalFormular(n) << endl;
  cout << sumOfDigits(n) << endl;
  cout << sumOfDigitsDesc(n) << endl;

  return 0;
}