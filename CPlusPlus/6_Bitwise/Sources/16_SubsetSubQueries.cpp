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
const int MAXSUM = 10001;

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

vector<bool> subsetSumBitset(vector<int> num, vector<int> query) {
  // using preprocessor MAXSUM
  bitset<MAXSUM> preSums;
  preSums[0] = 1;

  for (int x : num) {
    // {0,2} and {0,2} + 3 = {3,5} --> {0,2,3,5}
    // shifting meaning we add 3 to 0 and 2
    preSums |= (preSums << x);
  }

  vector<bool> result;
  for (int q : query) {
    if (q >= MAXSUM)
      result.push_back(false);
    else
      result.push_back(preSums[q]);
  }

  return result;
}

/*

        Time Complexity: n * maxQuery
        Space COmplexity: maxQuery + 1
*/
vector<bool> subsetSum(vector<int> num, vector<int> query) {
  int N = query.size();

  // consider only sum range from 0 to max element in query, since we just care about this range

  // index: sum
  // a[index]: true means we have this sum based on num array

  int maxEl = *max_element(query.begin(), query.end());

  vector<bool> preSums(maxEl + 1, false);
  preSums[0] = true;

  for (size_t i = 0; i < num.size(); i++) {
    int elInNum = num[i];

    for (int x = maxEl; x >= elInNum; x--) {
      if (preSums[x - elInNum]) {
        preSums[x] = true;  // if sum (x - elInNum) was possible before,
                            // then sum x is also possible now
      }
    }
  }

  // check if the sum can conducted from subset in preSums
  vector<bool> results(N, false);
  for (int i = 0; i < N; i++) {
    if (preSums[query[i]]) {
      results[i] = true;
    }
  }

  return results;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  vector<int> num;
  vector<int> query;
  vector<bool> results;

  inputVector(num);
  inputVector(query);

  auto result = subsetSum(num, query);
  auto result1 = subsetSumBitset(num, query);
  outputVector(result);
  outputVector(result1);

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