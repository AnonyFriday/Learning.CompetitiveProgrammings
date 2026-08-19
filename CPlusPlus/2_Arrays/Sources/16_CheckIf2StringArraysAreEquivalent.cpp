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
        concatenate 2 strings
        Time Complexity: O(n)
        Space: 0(n)
*/
bool naive(vector<string>& arr1, vector<string>& arr2) {
  if (arr1.size() == 0 || arr2.size() == 0) return false;

  string s1, s2;

  // concatenate
  s1 = std::accumulate(arr1.begin(), arr1.end(), string{});
  s2 = std::accumulate(arr2.begin(), arr2.end(), string{});

  // then compare
  return s1.compare(s2) == 0;
};

bool optimal(vector<string>& v1, vector<string>& v2) {
  if (v1.empty() || v2.empty()) return false;

  size_t i = 0, j = 0;    // index of vector
  size_t p1 = 0, p2 = 0;  // index of str

  while (i < v1.size() && j < v2.size()) {
    if (v1[i][p1] != v2[j][p2]) return false;

    // check next word in the vector, reset p, move i
    p1++;
    p2++;

    if (p1 == v1[i].size()) {
      p1 = 0;
      i++;
    }

    if (p2 == v2[j].size()) {
      p2 = 0;
      j++;
    }
  }

  // true when reaching at the end of both vector
  return i == v1.size() && j == v2.size();
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  vector<string> s1(3);
  vector<string> s2(8);

  inputVector(s1);
  inputVector(s2);

  outputVector(s1);
  outputVector(s2);

  // result
  cout << naive(s1, s2) << endl;
  cout << optimal(s1, s2) << endl;

  return 0;
}

// Get the largestNumber
int largest(int largestNum, int target) {
  return largestNum < target ? target : largestNum;
}

// Input Vector Array
template <typename T>
void inputVector(vector<T>& arr) {
  size_t i = 0;

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