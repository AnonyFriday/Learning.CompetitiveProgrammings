#include <bits/stdc++.h>

#include "./CustomHeaders/MyVector.hpp"

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

/*
        A user-defined vector based on the original vector from stl

        Data Members:
        - capacity
        - size
        - pointer


        Methods
        - constructor
                - start with the size of 2
        - destructor
                - delete[] ptr;
        - push_back
                - add to the back of the list
                - size++
        - pop
                                        - remove the back of the list
                                        - size--
        - reallocate
                                        - check if size >= capacity, then reallocate new array, double capacity and copy from originals

*/

// ==================================s

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  MyVector<int> v{1, 2, 3, 4, 5};
  const MyVector<int> v2{9, 9, 9, 9};
  std::cout << "Capacity before: " << v.capacity() << endl;

  std::cout << "Size before: " << v.size() << endl;

  std::cout << "Index 1 before: " << v[1] << endl;

  v[1] = 500;

  std::cout << "Index 1 after: " << v[1] << endl;

  // Not working since v2 is const object
  // v2[1] = 99;

  v.push_back(99999);
  v.push_back(99);
  v.push_back(99);
  v.push_back(99);
  v.push_back(99);
  v.push_back(100);
  std::cout << "Size after push_back: " << v.size() << endl;
  std::cout << "Capacity after push_back: " << v.capacity() << endl;

  std::cout << "Index 9: " << v[9] << endl;
  v.pop_back();
  v.pop_back();
  std::cout << "Size after pop_back: " << v.size() << endl;
  std::cout << "Is Empty: " << v.isEmpty() << endl;
  std::cout << "Front: " << v.front() << endl;
  std::cout << "Back: " << v.back() << endl;

  if (v.at(0).has_value()) {
    std::cout << "At 0: " << v.at(0).value() << endl;
  } else {
    std::cout << "Cannot access at location 0" << endl;
  }

  for (auto it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }

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