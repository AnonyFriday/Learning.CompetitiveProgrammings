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

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // b allocate n characters based on a, copy content into b's allocation

  std::string a = "Hello World";
  std::string b = a;

  std::cout << "Content of a: " << a
            << endl;

  std::cout << "Content of b: " << b
            << endl;

  std::cout << "Memory Address of a: " << &a
            << endl;

  std::cout << "Memory Address of b: " << &b
            << endl;

  std::cout << "Internal Buffer of a: " << (void*)a.data()
            << endl;

  std::cout << "Internal Buffer of b: " << (void*)b.data()
            << endl;

  // c free its own memory, point to continuous memory of a
  // and a pointers to the nullptr
  // - make sure only 1 ownership of the coneinuous memory allocation

  // - as you can see, the internal memory address of a and c are different, due to the behavior of SSO, short string stored at the stack object, instead allocated on the heap

  std::cout << "Internal Buffer of a before move: " << (void*)a.data()
            << endl;

  std::string c = std::move(a);
  std::cout << "Content of a: " << a << endl;
  std::cout << "Content of c: " << c << endl;

  std::cout << "Memory Address of a: " << &a << endl;
  std::cout << "Memory Address of c: " << &c << endl;

  std::cout << "Internal Buffer of a: " << (void*)a.data()
            << endl;

  std::cout << "Internal Buffer of c: " << (void*)c.data()
            << endl;

  // For large string, string store at the heap memory, not stack memory
  std::string d = string(1000, 'A');
  std::cout << "Internal Buffer of d before move: " << (void*)d.data()
            << endl;

  std::string e = std::move(d);

  std::cout << "Content of d: " << d << endl;
  std::cout << "Content of e: " << e << endl;

  std::cout << "Memory Address of d: " << &d << endl;
  std::cout << "Memory Address of e: " << &e << endl;

  std::cout << "Internal Buffer of d: " << (void*)d.data()
            << endl;

  std::cout << "Internal Buffer of e: " << (void*)e.data()
            << endl;
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