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
int largest(int largestNum, int target);

// = DO HERE ========================
// ===
// ==================================

class Product {
 private:
  int id;
  string n;

 public:
  int mrp;
  char* name;  // char name[100] is not assignable
  int selling_price;

  Product(){};

  Product(int id, string n, char* name, int mrp, int selling_price) {
    (*this).id = id;
    this->n = n;
    this->mrp = mrp;

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->selling_price = selling_price;
  }

  Product(const Product& X) {
    (*this).id = X.id;
    this->n = X.n;
    this->mrp = X.mrp;
    this->selling_price = X.selling_price;

    this->name = new char[strlen(X.name) + 1];
    strcpy(this->name, X.name);
  }

  void showDetails() {
    cout << id << endl;
    cout << n << endl;
    cout << mrp << endl;
    cout << name << endl;
    cout << selling_price << endl;

    cout << endl;
  }

  void setN(const string& newN) {
    this->n = newN;
  }

  void setName(const char* newName) {
    strcpy(this->name, newName);
  }

  // // Overding the assignment oeprator
  // void operator=(Product& X) {
  // (*this).id = X.id;
  // this->n = X.n;
  // this->mrp = X.mrp;
  // this->selling_price = X.selling_price;
  //
  // this->name = new char[strlen(X.name) + 1];
  // strcpy(this->name, X.name);
  // }
  //
  // ~Product() {
  // cout << "Deleteing" << name << endl;
  // if (name != NULL) {
  // delete[] name;
  // name = NULL;
  // }
  // }
};

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // 1. Demonstration on the copy constructor
  // shallow copy for the default setting
  char name[] = "VU KIM DUYxcvxcv";

  Product p1(1, "One", name, 12, 900);
  Product p2 = p1;

  strcpy(p2.name, "bla bla");

  p1.showDetails();
  p2.showDetails();

  // 2. Demonstraction on assignment operator
  // shallow copy for the default setting
  Product p3;

  p3 = p1;
  p3.setN("I LOVE YOU");
  char newName[] = "xxxxxxxxxxxxxxxxxxxxxxxf";
  p3.setName(newName);

  p1.showDetails();
  p3.showDetails();

  return 0;
}

// Get the largestNumber
int largest(int largestNum, int target) {
  return largestNum < target ? target : largestNum;
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