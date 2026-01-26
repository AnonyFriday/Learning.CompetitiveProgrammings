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

/*
  base 0: sum(i, j) = pre[j] - pre[i - 1]
  base 1: sum(i, j) = pre[j + 1] - pre[i - 1 + 1]
*/
int sum(const vector<vector<int>>& prefix, int r1, int r2, int c1, int c2) {
  int total = prefix[r2 + 1][c2 + 1];
  int left = prefix[r2 + 1 - 1][c1 + 1];
  int top = prefix[r1 + 1 - 1][c2 + 1];
  int cross = prefix[r1 + 1 - 1][c1 + 1 - 1];
  return total - left - top + cross;
}

int printMaxMangoTree(const vector<vector<int>>& matrix) {
  if (matrix.size() == 0) return 0;

  int n = matrix.size();
  int m = matrix[0].size();

  int maxSum = INT_MIN;

  // Create a prefix matrix base 1 with 0s padding
  vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));

  // pre[i] = pre[i - 1] + arr[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int left = p[i - 1][j];
      int top = p[i][j - 1];
      int cross = p[i - 1][j - 1];
      int newEl = matrix[i - 1][j - 1];  // because the matrix is 0-base
      int total = left + top + newEl - cross;
      p[i][j] = total;
    }
  }

  // Find the max of all 4 portions
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int topLeft = sum(p, 0, i, 0, j);
      int bottomLeft = sum(p, i + 1, n - 1, 0, j);
      int topRight = sum(p, 0, i, j + 1, m - 1);
      int bottomRight = sum(p, i + 1, n - 1, j + 1, m - 1);
      int minSum = min(min(topLeft, bottomLeft), min(topRight, bottomRight));

      maxSum = max(maxSum, minSum);
    }
  }

  return maxSum;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  vector<vector<int>> matrix = {
      {1, 0, 0, 1},
      {1, 1, 1, 1},
      {0, 0, 0, 0},
      {1, 1, 1, 1},
  };

  int maxSum = printMaxMangoTree(matrix);

  cout << maxSum;

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