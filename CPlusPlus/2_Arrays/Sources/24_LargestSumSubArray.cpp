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
void inputVector(vector<int>& arr);

template <typename T>
void outputVector(vector<T>& arr);

template <typename T>
void output2DVector(vector<vector<T>>& arr);

// Maths
int fact(int n);
double calBinominalCoefficient(int n, int k);
int reverse(int n);
int largest(int largestNum, int target);

// = DO HERE ========================

int largestSubarraySum(vector<int>& arr) {
  if (arr.size() == 0) return 0;

  int N = arr.size();

  int largestSum = INT_MIN;

  // 1. Calcualte the prefix sum
  // - sum[i] = sum[i - 1] + a[i]
  // 1 2 3 4 5 | 7 8 | 9 10
  //         i      j
  // [7,8] = sum to j - sum to i;

  vector<int> prefixSum(N);
  prefixSum[0] = arr[0];

  for (int i = 1; i < N; i++) {
    prefixSum[i] = prefixSum[i - 1] + arr[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      int sumItoJ;

      if (i > 0) {
        sumItoJ = prefixSum[j] - prefixSum[i - 1];
      } else {
        sumItoJ = prefixSum[j];
      }

      largestSum = max(largestSum, sumItoJ);
    }
  }

  return largestSum;
}

int largestSubarraySumKadane(vector<int>& arr) {
  if (arr.size() == 0) return 0;

  int N = arr.size();

  int largestSum = INT_MIN;
  int largestNegative = INT_MIN;

  // Follow the trick
  // - Imaging 2 bag, myBag and myLargestBag
  // - After adding new coin to my bag, if my bag is negative, better throw away my bag buz i'm in debt
  // - If it's positive, just keep it

  int currentSum = 0;

  for (auto el : arr) {
    if (el < 0) {
      largestNegative = max(largestNegative, el);  // tracking the highest negative anyway, for the case of all negatives
    }

    currentSum += el;

    if (currentSum < 0) {
      currentSum = 0;  // throw my bag
      continue;
    }

    largestSum = max(largestSum, currentSum);
  }

  // handle the case for all negatives
  if (largestSum == INT_MIN) {
    return largestNegative;
  }

  return largestSum;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> arr(n);
  inputVector(arr);
  outputVector(arr);

  cout << largestSubarraySum(arr) << endl;
  cout << largestSubarraySumKadane(arr) << endl;

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