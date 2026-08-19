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

// Input Vector Array
void inputArray(vector<int>& arr);

// Calculate factorial
int fact(int n);

// Calculate nCk
// - counting(a,b) and (b,a) are the same value
// - formular: n! / k!(n-k)!
double calBinominalCoefficient(int n, int k);

// Reverse a number
int reverse(int n);

// = DO HERE ========================

int getFrequency(int* arr, int n, int target) {
  if (n <= 0) return 0;

  int count = arr[n - 1] == target ? 1 : 0;

  int res = count + getFrequency(arr, n - 1, target);

  return res;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int data[] = {10, 20, 5, 10, 30, 10, 5, 40};
  int size = sizeof(data) / sizeof(data[0]);

  printf("Array: {10, 20, 5, 10, 30, 10, 5, 40}\n");

  int target1 = 10;
  int target2 = 5;
  int target3 = 99;

  // Test Case 1: Target 10
  int freq1 = getFrequency(data, size, target1);
  printf("Frequency of %d is: %d\n", target1, freq1);  // Expected: 3

  // Test Case 2: Target 5
  int freq2 = getFrequency(data, size, target2);
  printf("Frequency of %d is: %d\n", target2, freq2);  // Expected: 2

  // Test Case 3: Target 99
  int freq3 = getFrequency(data, size, target3);
  printf("Frequency of %d is: %d\n", target3, freq3);  // Expected: 0

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