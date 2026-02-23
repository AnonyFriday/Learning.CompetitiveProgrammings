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

void applyRatio(int ratio) {
  ratio = ratio * 2;
}

void applyTax(int& income) {
  float tax = 0.10;
  income = income - income * tax;
}

void applyInsurrance(int* money) {
  *money = *money + 100;
}

void newAndDelete(int size) {
  int* arr = new int[size];

  for (int i = 0; i < size; i++) {
    arr[i] = i * 2;
  }

  cout << arr << endl;
  cout << *arr << endl;
  cout << *(arr + 1) << endl;

  delete[] arr;
}

// Shared Pointers, Weak Pointer, Strong Pointer

class Robot {
 public:
  Robot() { std::cout << "Robot assembled.\n"; }
  ~Robot() { std::cout << "Rovot destroyed.\n"; }
  void greet() { std::cout << "Hello, world!\n"; }
};

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // === Pointer and Reference ===============

  int income, money, ratio;
  int* initialPtr = nullptr;
  int& initialRef = income;
  cin >> income >> money >> ratio;

  // pass by value
  applyRatio(ratio);

  // pass by reference
  // - a function that take an argument as a reference that pointing to the same passed variable
  // - a reference is an alias, share the same memory address
  applyTax(income);

  // pass by pointer
  // - a function has an argument as a pointer pointing to the address of the variable
  applyInsurrance(&money);

  cout << income << endl;
  cout << money << endl;
  cout << ratio << endl;
  cout << initialPtr << endl;
  cout << initialRef << endl;

  // === New & Delete ====================
  newAndDelete(10);

  // === Shared Pointers, Weak Pointer, Strong Pointer ====================

  // Shared Pointer
  // - Better than new, since we are creating ptr1 point to the shared object Robot

  std::shared_ptr<Robot> ptr1 = std::make_shared<Robot>();
  cout << "Count: " << ptr1.use_count() << "\n";  // count: 1

  {
    std::shared_ptr<Robot> ptr2 = ptr1;
    cout << "Count: " << ptr1.use_count() << "\n";  // count: 2

    ptr2->greet();

    // When goes out of scope, the ptr2 is being destroyed
  }

  cout << "Count: " << ptr1.use_count() << "\n";  // count: 1

  // Weak Pointer
  // - weak pointer only observe the object
  // - using .lock() to return the shared_ptr, with ownership of that resource

  std::weak_ptr<Robot> ptr3 = ptr1;
  cout << "Count: " << ptr3.use_count() << "\n";  // count: 1

  std::shared_ptr<Robot> ptr3_shared = ptr3.lock();
  ptr3_shared->greet();

  {
    std::weak_ptr<Robot> ptr4 = ptr1;
    ptr1.reset();
    ptr3.reset();
    ptr4.reset();                                   // deallocate the object
    cout << "Count: " << ptr4.use_count() << "\n";  // count: 1
  }

  // Unique Pointer
  // - only 1 ptr - 1 object
  std::unique_ptr<Robot> ptrUnique = std::make_unique<Robot>();
  ptrUnique->greet();

  // - Compiler Error since unqiue object can only be pointed by 1 unique pointer
  // std::unique_ptr<Robot> owner2 = ptrUnique;
  std::unique_ptr<Robot> owner2 = std::move(ptrUnique);
  owner2->greet();

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