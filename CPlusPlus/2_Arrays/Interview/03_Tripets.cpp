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
void inputArray(vector<int>& arr);

template <typename T>
void outputArray(vector<T>& arr);

template <typename T>
void output2DArray(vector<vector<T>>& arr);

// Maths
int fact(int n);
double calBinominalCoefficient(int n, int k);
int reverse(int n);

// = DO HERE ========================

// the triplet is unique, meaning (a,b,c) = (b,a,c)
// Using sorted(NLogN) + two pointer (N^N) to find the triplet
// - for each element, find the pair that match the target
// - return if founed
vector<vector<int>> triplet(vector<int>& arr, int target) {
  if (arr.size() == 0 || arr.size() < 3) return {};

  vector<vector<int>> res;

  // 1. sort first
  std::sort(arr.begin(), arr.end());

  // 2. each element
  for (auto it = arr.begin(); it != arr.end(); it++) {
    int el = *it;

    // handle duplicate *it
    if (it != arr.begin() && *it == *(it - 1)) {
      continue;
    }

    int targetPair = target - el;

    // 3. find pair
    auto left = it + 1;
    auto right = arr.end() - 1;

    while (left < right) {
      int pair = (*left) + (*right);

      // 8 < 12, then decrease right
      // 8 > 2, then increase left
      // if 8 = 8, move forward pointers to find next pair
      if (pair == targetPair) {
        res.push_back({el, *left, *right});
        left++;
        right--;

        // handle duplicate element from the previous element
        while ((left < right) && ((*right) == (*(right + 1)))) {
          right--;
        }

        while ((left < right) && ((*left) == (*(left - 1)))) {
          left++;
        }

      } else if (pair > targetPair) {
        right--;
      } else {
        left++;
      }
    }
  }

  return res;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n, target;
  cin >> n >> target;
  vector<int> arr(n);

  inputArray(arr);
  outputArray(arr);

  auto res = triplet(arr, target);
  output2DArray(res);

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

// Ouput 2D vector array
template <typename T>
void output2DArray(vector<vector<T>>& arr) {
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

// Output Vector Array
template <typename T>
void outputArray(vector<T>& arr) {
  for (size_t i = 0; i < arr.size(); i++) {
    std::cout << arr[i];

    // print the last seperator
    if (i != (arr.size() - 1)) {
      std::cout << ",";
    }
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