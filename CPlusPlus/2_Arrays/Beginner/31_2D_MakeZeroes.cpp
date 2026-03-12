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
void input2DVector(vector<vector<T>>& arr);

template <typename T>
void outputVector(vector<T>& arr);

template <typename T>
void output2DVector(vector<vector<T>>& arr);

template <typename T>
void reverse(vector<T>& arr, size_t start, size_t end);

// Strings
vector<string> split(const string& s, char delimitor);

// Maths
int fact(int n);
double calBinominalCoefficient(int n, int k);
int reverse(int n);
int largest(int largestNum, int target);

// = DO HERE ========================

/*
   Time Complexity is n ^ m
   Space is m or n
*/
void makeZeroes(vector<vector<int>>& m) {
  if (m.empty() || m[0].empty()) return;

  // store rows and cols
  vector<int> rs;
  vector<int> cs;

  // if first el of the row or col is 0, mark first el of the row or col as 0 for notation
  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m[0].size(); j++) {
      if (m[i][j] == 0) {
        rs.push_back(i);
        cs.push_back(j);
      }
    }
  }

  // filling row
  for (int r : rs) {
    for (size_t i = 0; i < m[0].size(); i++) {
      m[r][i] = 0;
    }
  }

  // filling col
  for (int c : cs) {
    for (size_t i = 0; i < m.size(); i++) {
      m[i][c] = 0;
    }
  }
}

/*
   Time Complexity is n ^ m
   Space is 1
   Marking first row and second row for 0s appearance
*/
void makeZeroes2(vector<vector<int>>& m) {
  if (m.empty() || m[0].empty()) return;

  // check first row, first col
  size_t rs = m.size();
  size_t cs = m[0].size();
  bool firstRow = false, firstCol = false;

  // check first row
  for (size_t i = 0; i < rs; i++) {
    if (m[0][i] == 0) firstRow = true;
  }

  // check first col
  for (size_t i = 0; i < cs; i++) {
    if (m[i][0] == 0) firstCol = true;
  }

  // marking 0s now at the first row and first col, start from index 1
  for (size_t i = 1; i < rs; i++) {
    for (size_t j = 1; j < cs; j++) {
      if (m[i][j] == 0) {
        m[0][j] = 0;
        m[i][0] = 0;
      }
    }
  }

  // filling row and col by checking marker
  for (size_t i = 1; i < rs; i++) {
    for (size_t j = 1; j < cs; j++) {
      if (m[0][j] == 0 || m[i][0] == 0) {
        m[i][j] = 0;
      }
    }
  }

  // now fix the first row and first col base on original state
  if (firstRow)
    for (size_t j = 0; j < cs; j++)
      m[0][j] = 0;

  // fix first column
  if (firstCol)
    for (size_t i = 0; i < rs; i++)
      m[i][0] = 0;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // input
  vector<vector<int>> matrix;
  input2DVector(matrix);

  // logic
  // makeZeroes(matrix);
  makeZeroes2(matrix);

  // output
  output2DVector(matrix);

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

// Input 2D Vector array
template <typename T>
void input2DVector(vector<vector<T>>& arr) {
  string line;

  while (getline(cin, line, '\n')) {
    vector<T> row;
    auto parts = split(line, ',');
    for (const string& el : parts) {
      stringstream ss(el);
      T value;
      ss >> value;  // convert string to T
      row.push_back(value);
    }

    arr.push_back(row);
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

// Reverse an array of T element
template <typename T>
void reverse(vector<T>& arr, size_t start, size_t end) {
  if (arr.size() == 0 || start < 0 || end >= arr.size()) return;

  while (start < end) {
    std::swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

// Split a string based on delimitor
vector<string> split(const string& s, char delimitor) {
  vector<string> result;

  if (s.size() == 0) return result;

  stringstream ss(s);
  string word;
  while (getline(ss, word, delimitor)) {
    result.push_back(word);
  }

  return result;
}