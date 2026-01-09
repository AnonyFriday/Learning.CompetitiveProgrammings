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
#include <unordered_map>
// #include <vector>
//
using namespace std;

const double E = 1e-8;
const double PI = acos(-1);

// Vectors
void inputVector(vector<int>& arr);

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

pair<int, int> twoSum(vector<int>& nums, int target) {
  if (nums.size() == 0) return {-1, -1};

  int n = nums.size();
  if (n < 2 || n > 10000) return {-1, -1};

  pair<int, int> result = {-1, -1};
  unordered_map<int, int> dict = {};

  for (int i = 0; i < n; i++) {
    // find return an iterator
    int complement = target - nums[i];
    auto it = dict.find(complement);

    if (it != dict.end()) {
      return {it->second, i};
    } else {
      dict[nums[i]] = i;
    }
  }

  return {-1, -1};
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automasstically calling cout.flush()
  cin.tie(0);

  int target, n;
  cin >> target >> n;

  vector<int> nums(n);
  inputVector(nums);
  outputVector(nums);

  auto pair = twoSum(nums, target);
  cout << pair.first << " " << pair.second;

  return 0;
}

// Get the largestNumber
int largest(int largestNum, int target) {
  return largestNum < target ? target : largestNum;
}

// Input Vector Array
void inputVector(vector<int>& arr) {
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