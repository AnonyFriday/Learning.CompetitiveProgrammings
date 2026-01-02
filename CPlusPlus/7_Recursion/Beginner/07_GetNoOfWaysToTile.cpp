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

/*
        Given a tile 2x1
        How many number of way to tile 2xn

        if  we make a draft, we can see
        - 2x4 = 5 ways
        - 2x3 = 3 ways
        - 2x2 = 2 ways
        - 2x1 = 1 ways
        - 2x0 = 1 ways
        --> fib
*/
int noOfWayToTileBoard(int n) {
  if (n == 0) return 1;
  if (n == 1) return 1;

  return noOfWayToTileBoard(n - 1) + noOfWayToTileBoard(n - 2);
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n;
  cin >> n;
  cout << noOfWayToTileBoard(n) << endl;

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
