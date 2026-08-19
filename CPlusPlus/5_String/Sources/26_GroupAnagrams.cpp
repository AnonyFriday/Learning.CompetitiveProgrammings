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

/*
        Provide a custom hash function for the mask array
        instead of converting to string or integer

bucket0
bucket1 → [key,value]
bucket2
bucket3 → [key,value]
bucket4 → [key,value]

*/

struct CustomHasher {
  std::size_t operator()(const array<int, 26>& mask) const {
    size_t h = 0;

    for (const size_t& el : mask) {
      h = h * 31 + el;
    }

    return h;
  }
};

vector<vector<string>> naive2(
    const vector<string>& strs) {
  vector<vector<string>> result;

  if (strs.empty()) return result;

  unordered_map<array<int, 26>, vector<string>, CustomHasher> groups;

  for (const string& str : strs) {
    // create the mask key as defined in the hasher
    array<int, 26> mask{};

    for (size_t i = 0; i < str.size(); i++) {
      mask[str[i] - 'a']++;
    }

    groups[mask].push_back(str);
  }

  for (auto& [key, g] : groups) {
    result.push_back(g);
  }

  return result;
}

/*
        Using frequency vector to reduce the time complexity for sorting
        Time complexity: nk
        Space complexity: nk

*/

string strToBinary(const string& str) {
  vector<int> mask(26, 0);
  for (size_t i = 0; i < str.size(); i++) {
    mask[str[i] - 'a']++;
  }

  string result;
  for (const size_t& el : mask) {
    result += el;
  }

  return result;
}

vector<vector<string>> naive1(
    const vector<string>& strs) {
  vector<vector<string>> result;

  if (strs.empty()) return result;

  unordered_map<string, vector<string>> groups;

  // sorting each string in the array
  for (string str : strs) {
    const string mask = strToBinary(str);
    if (groups.find(mask) == groups.end()) {
      vector<string> g;
      groups[mask] = g;
    }

    groups[mask].push_back(str);
  }

  for (auto& [key, g] : groups) {
    result.push_back(g);
  }

  return result;
}

/*
        Time Complexity: nklogk
        Space complexity: nk
*/
vector<vector<string>> naive(
    const vector<string>& strs) {
  vector<vector<string>> result;

  if (strs.empty()) return result;

  unordered_map<string, vector<string>> groups;

  // sorting each string in the array
  for (string str : strs) {
    // klogk
    string sorted = str;
    std::sort(sorted.begin(), sorted.end());

    if (groups.find(sorted) == groups.end()) {
      vector<string> g;
      groups[sorted] = g;
    }
    groups[sorted].push_back(str);
  }

  for (auto& [key, g] : groups) {
    result.push_back(g);
  }

  return result;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  vector<string> v;
  inputVector(v);

  // logic
  auto result = naive(v);
  auto result1 = naive1(v);
  auto result2 = naive2(v);
  output2DVector(result);
  output2DVector(result1);
  output2DVector(result2);

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