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

void printNumbersAsc(int arr[], int n, int i = 0) {
  if (i == n) return;

  cout << arr[i] << " ";

  printNumbersAsc(arr, n, i + 1);
}

void printNumberAsc2(int arr[], int n) {
  if (n <= 0) return;

  printNumberAsc2(arr, n - 1);

  // When reaching the top of stack,
  // start executing the code, then the function call is destroyed
  cout << arr[n - 1] << " ";
}

// This is a technique called toward a recursive
// anything will be called before a next recursive call
void printNumbersDesc(int arr[], int n) {
  if (n <= 0) return;

  cout << arr[n - 1] << " ";

  printNumbersDesc(arr, n - 1);
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n = 6;

  int arr[] = {1, 2, 3, 4, 5, 6};

  printNumbersAsc(arr, n);
  cout << endl;
  printNumbersDesc(arr, n);
  cout << endl;
  printNumberAsc2(arr, n);

  return 0;
}