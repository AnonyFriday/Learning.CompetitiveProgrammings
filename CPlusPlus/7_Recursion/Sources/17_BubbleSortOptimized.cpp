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
template <typename T>
vector<T> split(const string& s, char delimitor);

// Maths
int fact(int n);
double calBinominalCoefficient(int n, int k);
int reverse(int n);
int largest(int largestNum, int target);

// = DO HERE ========================

vector<int> bubbleSort(vector<int> a) {
  if (a.empty() || a.size() == 1) return a;

  // for each fix location, we loop to bubble up the longest element to the right

  int n = a.size();
  bool isSwapped = false;

  for (int i = 0; i < n - 1; i++) {
    isSwapped = false;
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        isSwapped = true;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }

    // if they are in order, just continue;
    if (!isSwapped) continue;
  }

  return a;
}

/*
        Time: O(N^2)
        Space: O(N)
*/

vector<int> bubbleSortRecursive(vector<int> a, int n) {
  // base case
  if (a.empty() || n == 0 || n == 1) return a;

  // allocate the highest for each pass, then move to the smaller array on recursion
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] < a[i - 1]) {
      int temp = a[i - 1];
      a[i - 1] = a[i];
      a[i] = temp;
    }
  }

  return bubbleSortRecursive(a, n - 1);
}

/*

Replacing the traditional inner for loop

*/
vector<int> bubbleSortRecursive2(vector<int> a, int n, int i) {
  // base case
  if (a.empty() || n == 0 || n == 1) return a;

  // when i == n -1, reset i, reduce the subarray
  if (i == n - 1) {
    return bubbleSortRecursive2(a, n - 1, 0);
  }

  // instead of for loop, storing i at each call stack
  if (a[i] > a[i + 1]) {
    int temp = a[i + 1];
    a[i + 1] = a[i];
    a[i] = temp;
  }

  return bubbleSortRecursive2(a, n, i + 1);
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  vector<int> a;
  inputVector(a);

  vector<int> result = bubbleSort(a);
  vector<int> result1 = bubbleSortRecursive(a, a.size());
  vector<int> result2 = bubbleSortRecursive2(a, a.size(), 0);

  outputVector(result);
  outputVector(result1);
  outputVector(result2);

  return 0;
}

// Get the largestNumber
int largest(int largestNum, int target) {
  return largestNum < target ? target : largestNum;
}

// Input Vector Array
template <typename T>
void inputVector(vector<T>& arr) {
  string line;
  getline(cin, line, '\n');
  arr = split<T>(line, ',');
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
    auto parts = split<T>(line, ',');
    for (const T& value : parts) {
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
template <typename T>
vector<T> split(const string& s, char delimitor) {
  vector<T> result;

  if (s.size() == 0) return result;

  stringstream ss(s);
  string word;
  while (getline(ss, word, delimitor)) {
    stringstream convert(word);

    T value;
    convert >> value;

    result.push_back(value);
  }

  return result;
}