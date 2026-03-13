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

// Input Vector Array
void inputArray(vector<int>& arr);

// Calculate factorial
int fact(int n);

// Calculate nCk
// - counting(a,b) and (b,a) are the same value
// - formular: n! / k!(n-k)!
double calBinominalCoefficient(int n, int k);

// = DO HERE ========================

bool isPalindromeNumber(int n) {
  if (n == 0 || (n / 10) == 0) return false;

  int ac = n;
  int bc = n;
  int p = 1;
  int res = 0;

  // 1234
  // 4321

  // get no of digits
  // 1234 10
  // 123  100
  // 12   1000
  // 1    10000
  while (ac > 0) {
    p *= 10;
    ac /= 10;
  }

  // cut off 1 p
  p /= 10;

  // 4000
  // 4300
  // 4320
  // 4321
  while (p > 0) {
    int digit = bc % 10;
    res += digit * p;
    p /= 10;
    bc /= 10;
  }

  return res == n;
};

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n;
  cin >> n;
  cout << isPalindromeNumber(n) << endl;

  return 0;
}

// Input Vector Array
void inputArray(vector<int>& arr) {
  int i = 0;
  while (i < arr.size()) {
    cin >> arr[i];
    i++;
  }
}

// Calculate factorial
int fact(int n) {
  if (n == 0 || n == 1) return 1;

  return n * fact(n - 1);
}

// Calculate nCk
// - counting(a,b) and (b,a) are the same value
// - formular: n! / k!(n-k)!
double calBinominalCoefficient(int n, int k) {
  if (n == k) return 1.0;  // 1 way to choose everything
  if (k == 1) return n;    // choose 1 item has N posibilities
  if (k == 0) return 1.0;  // exactly 1 way to choose nothing

  return (double)fact(n) / (double)(fact(k) * fact(n - k));
}
