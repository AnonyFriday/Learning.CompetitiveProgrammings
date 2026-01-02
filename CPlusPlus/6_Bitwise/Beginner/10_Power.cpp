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

// Reverse a number
int reverse(int n);

// = DO HERE ========================

// a ^ b
double pow(double a, long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;

  // looop over b as in binary
  // 15^10 = 15^(8 + 2) = 15^8 x 15^2
  //                    = 15^(2^3) x 1 x 15^(2^1) x 1
  //                    =       1    0   1          0
  // only loop through the b in binary, if last bit is 1
  // then accumulate the result by time base with accumulate of b

  int res = 1;
  int base = a;

  // This is math
  // a^-b = 1/a^b

  if (b < 0) {
    base = 1.0 / base;
    b = -b;
  }

  while (b > 0) {
    // if last bit is 1
    if ((b & 1) > 0) {
      res = res * base;
    }

    // 4^1, 4^2, 4^4, 4^8, 4^16, ...
    // instead of accumulate 1,2,4,8
    // we accumulate a^1,..., but still tracking the binary b
    base = base * base;
    b = b >> 1;
  }

  return res;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  cout << pow(4, 4) << endl;
  cout << pow(4, -2) << endl;

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

// Reverse a number
int reverse(int n) {
  if (n == 0 || n == 1) return n;

  int res = 0;

  while (n > 0) {
    int digit = n % 10;
    res = res * 10 + digit;
    n /= 10;
  }

  return res;
}