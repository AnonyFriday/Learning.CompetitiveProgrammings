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

/*
        Apply 2 Pointer technique
        - 2 pointer for reading count
        - 1 pointer for writing

        For this scope, we gonna return the length of compressed string

        shrink_to_fit: resize the capacity, not good
                                resize: updating the internal counter, but still left remaning
*/
vector<char> compress(vector<char>& chars) {
  int n = chars.size();
  if (n <= 1) return chars;

  // read for scanning the chars array
  // write for keep tracking the result array index
  int readStart = 0;
  int readEnd = 0;
  int write = 0;

  while (readStart < n) {
    while (readEnd < n && chars[readEnd] == chars[readStart]) {
      readEnd++;
    }

    int count = readEnd - readStart;
    chars[write++] = chars[readStart];

    // a1 -> a
    if (count > 1) {
      // convert since it's the chars array
      string countStr = to_string(count);
      for (auto c : countStr) {
        chars[write++] = c;
      }
    }

    readStart = readEnd;  // reset to the next group
  }

  chars.resize(write);

  return chars;
}

string compress(string str) {
  int n = str.length();

  if (n <= 1) return str;
  string result;

  for (int i = 0; i < n; i++) {
    // count always equals to 1
    int count = 1;

    // this loop is for counting only
    while (i < n - 1 && str[i] == str[i + 1]) {
      count++;
      i++;
    }

    result += str[i];

    if (count > 1) {
      result += to_string(count);
    }
  }

  return result;
}

// ==================================

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);
  int n;
  cin >> n;

  vector<char> input(n);
  inputVector<char>(input);

  // resize the array
  auto compressedArray = compress(input);

  for (auto el : compressedArray) {
    cout << el;
  }

  string inputStr(input.begin(), input.end());
  cout << "\n"
       << compress(inputStr) << endl;

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