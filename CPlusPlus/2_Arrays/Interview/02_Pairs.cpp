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

// Maths
int fact(int n);
double calBinominalCoefficient(int n, int k);
int reverse(int n);

// = DO HERE ========================

/*

        Time Complexity: O(n): due to loop the entire array for finding the perfect match
        Space Complexity: O(n) due to extra set or map

Reason didn't sort first like Triplet solution then find is because the time complexity of sorting is NLogN, meaning it's a bottle neck of the finding element O(n)
*/
std::vector<int> calPairs(vector<int> arr, int target) {
  unordered_map<int, int> seen_values;
  vector<int> res;

  // check if the compliement el exist or not (count = 1)
  // if count = 1, then return both,
  // if no then add to freq, and count = 1
  for (int i = 0; i < arr.size(); i++) {
    int el = arr[i];
    int com = target - el;
    if (seen_values.count(com)) {
      res.push_back(com);
      res.push_back(el);
      return res;
    } else {
      seen_values[el] = 1;
    }
  }

  return res;
}

// just like map but use set
std::vector<int> calPairsSet(vector<int> arr, int target) {
  unordered_set<int> seen_values;
  vector<int> res;

  // check if the compliement el exist or not (count = 1)
  // if count = 1, then return both,
  // if no then add to freq, and count = 1
  for (int i = 0; i < arr.size(); i++) {
    int el = arr[i];
    int com = target - el;
    auto it = seen_values.find(com);

    if (it != seen_values.end()) {
      res.push_back(com);
      res.push_back(el);
      return res;
    } else {
      seen_values.insert(el);
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

  int target, n;
  cin >> n >> target;

  vector<int> arr(n);

  inputArray(arr);
  outputArray<int>(arr);
  auto res = calPairs(arr, target);
  auto resSet = calPairs(arr, target);
  outputArray(res);
  outputArray(resSet);

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