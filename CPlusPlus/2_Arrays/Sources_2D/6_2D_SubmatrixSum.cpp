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

// Vectors
template <typename T>
void inputVector(vector<T>& arr);

template <typename T>
void outputVector(vector<T>& arr);

template <typename T>
void output2DVector(vector<vector<T>>& arr);

template <typename T>
void reverse(vector<T>& arr);

// Maths
int fact(int n);
double calBinominalCoefficient(int n, int k);
int reverse(int n);
int largest(int largestNum, int target);

// = DO HERE ========================

// Generate the prefix sum
// pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + arr[i][j]
//           	 - pre[i-1][j-1]

// Sum in range (rs -> re, cs -> ce)
// sumRange = pre[re][ce] - pre[rs-1][cl] - pre[re][cs-1] + pre[rs-1][cs-1]

// edge case
// if any part has index < 0, then ignore that part of     the formular

vector<vector<int>> prefixArray(const vector<vector<int>>& arr) {
  int n = arr.size();
  int m = arr[0].size();

  vector<vector<int>> pre(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = arr[i][j];
      if (i > 0) sum += pre[i - 1][j];
      if (j > 0) sum += pre[i][j - 1];
      if (i > 0 && j > 0) sum -= pre[i - 1][j - 1];

      pre[i][j] = sum;
    }
  }

  return pre;
}

int subMatrixSum(
    const vector<vector<int>>& arr,
    int rs, int re, int cs, int ce) {
  if (arr.size() == 0 || arr[0].size() == 0) return 0;

  auto pre = prefixArray(arr);

  // calculate
  auto sum = pre[re][ce];

  if (rs > 0) sum -= pre[rs - 1][ce];
  if (cs > 0) sum -= pre[re][cs - 1];
  if (rs > 0 && cs > 0) sum += pre[rs - 1][cs - 1];

  return sum;
}

// Claculate the sum based on the prefix index

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);
  int rs, re, cs, ce;
  cin >> rs >> re >> cs >> ce;

  vector<vector<int>> mat = {
      {1, 2, 3, 4, 6},
      {5, 3, 8, 1, 2},
      {4, 6, 7, 5, 5},
      {2, 4, 8, 9, 4}};

  auto result = subMatrixSum(mat, rs, re, cs, ce);

  cout << result;

  return 0;
}

// Get the largestNumber
int largest(int largestNum, int target) {
  return largestNum < target ? target : largestNum;
}

// Input Vector Array
template <typename T>
void inputVector(vector<T>& arr) {
  int i = 0;
  while (i < arr.size()) {
    cin >> arr[i];
    i++;
  }
}

// Output Vector Array
template <typename T>
void outputVector(vector<T>& arr) {
  for (size_t i = 0; i < arr.size(); i++) {
    std::cout << arr[i];

    // print the last seperator
    if (i != (arr.size() - 1)) {
      std::cout << ",";
    }
  }

  std::cout << endl;
}

// Ouput 2D vector array
template <typename T>
void output2DVector(vector<vector<T>>& arr) {
  for (auto el : arr) {
    for (size_t i = 0; i < el.size(); i++) {
      std::cout << el[i];
      if (i != (el.size() - 1)) {
        std::cout << ",";
      }
    }
    std::cout << endl;
  }
  std::cout << endl;
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

// Reverse an array of T element
template <typename T>
void reverse(vector<T>& arr, int start, int end) {
  if (arr.size() == 0 || start < 0 || end >= arr.size()) return;

  while (start < end) {
    std::swap(arr[start], arr[end]);
    start++;
    end--;
  }
}