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

ostream& operator<<(ostream& os, const pair<string, int>& f) {
  os << "(" << f.first << "," << f.second << ")";
  return os;
}

vector<pair<string, int>> sortFruits(
    const vector<pair<string, int>>& v,
    const string& mode) {
  vector<pair<string, int>> result(v);

  if (v.empty()) return result;

  std::sort(result.begin(), result.end(),
            [&mode](const pair<string, int>& a,
                    const pair<string, int>& b) {
              if (mode == "price") {
                return a.second < b.second;
              } else if (mode == "name") {
                return a.first < b.first;
              } else {
                return a.second < b.second;
              }
            });

  return result;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // logic here
  vector<pair<string, int>> v;
  string mode;
  string line;

  // input
  getline(cin, mode);

  while (getline(cin, line, '\n')) {
    pair<string, int> p;

    auto pair = split(line, ',');
    p.first = pair[0];
    p.second = stoi(pair[1]);

    v.push_back(p);
  };

  // logic
  auto result = sortFruits(v, mode);

  // output
  outputVector(result);

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
      std::cout << endl;
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