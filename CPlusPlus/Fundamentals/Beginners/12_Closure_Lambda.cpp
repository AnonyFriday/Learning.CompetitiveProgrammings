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

// ==================================
// = DO HERE ========================
// ==================================

// 1. This is not a closure,
int x = 20;
int comparerFunc(int a, int b) {
  cout << "HERE: " << x++;
  return a > b;
}

// 2. This is a function return an inner function with the closure
auto makeAdder(int base) {
  return [base](int x) {
    return x + base;
  };
};

// 3. If you want to modify the closure's variable, using mutable
// - By default, you cannot modify the varialbe cuz const
auto makePhoneCaptureByValue(std::string& prefix) {
  int numberOfPhones = 0;

  // since capture by value, then numberOfPhones inside the closure is 0, not being affected by += 100
  auto f = [prefix, numberOfPhones](int number) mutable -> string {
    numberOfPhones++;
    std::string prefixStr = "CODE_" + to_string(numberOfPhones) + "_" + prefix;
    return prefixStr + "-" + std::to_string(number);
  };

  numberOfPhones += 100;
  return f;
}

// 4. Capture by refernce
auto makePhoneCaptureByReference(std::string& prefix) {
  int numberOfPhones = 0;

  // when calling (), numberOfPhones will be executing first from 0 to 100
  // when calling second (), same original numberOfPhones is referenced and increated to 101
  auto f = [prefix, &numberOfPhones](int number) mutable -> string {
    numberOfPhones++;
    std::string prefixStr = "CODE_" + to_string(numberOfPhones) + "_" + prefix;
    return prefixStr + "-" + std::to_string(number);
  };

  numberOfPhones += 100;
  return f;
}

// 5. Capture by refernce with Smart Pointers
auto makePhoneCaptureByReferenceSmart(std::string& prefix) {
  std::unique_ptr<int> numberOfPhones = std::make_unique<int>(0);

  // here, after first execution, the ptr is destroyed from the stack, but the object in heap still maintain and the owenership has been transfer since the first exeuction

  /*

        STACK                         HEAP
        ------                        ------
        numberOfPhones ───────────►  int(0)

  */

  (*numberOfPhones) += 100;

  /*

        Before move:
        outer ptr ──► heap int

        After move:
        lambda ptr ─► heap int
        outer ptr = nullptr
        outer ptr in the stack has been destroyed

  */

  auto f = [prefix, numberOfPhones = std::move(numberOfPhones)](int number) mutable -> string {
    (*numberOfPhones)++;

    std::string prefixStr = "CODE_" + to_string(*numberOfPhones) + "_" + prefix;

    return prefixStr + "-" + std::to_string(number);
  };

  // Since already move the ownership to the inner ptr, it will raise nullptr and cause runtime error

  // (*numberOfPhones) += 100;

  return f;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // 1. lambda function defined inside
  vector<int> v{4, 2, 67, 2, 90};
  std::sort(
      v.begin(), v.end(),
      [](int a, int b) {
        return a > b;
      });
  outputVector(v);

  // 2. Lambda function passed as an argument
  auto comparer = [](int a, int b) {
    return a < b;
  };

  std::sort(v.begin(), v.end(), comparer);
  outputVector(v);

  // 3. Passing a regular function as an argument
  std::sort(v.begin(), v.end(), comparerFunc);
  outputVector(v);

  // 4. A closure capture x by reference, will directly affect the original x
  int x = 300;
  auto f = [&x](int lcs) {
    cout << "Print x and lcs: " << x << ", " << lcs << endl;
    x += 1000;
    cout << "Print x and lcs: " << x << ", " << lcs << endl;
  };

  f(123);
  f(123);

  cout << "x after: " << x << endl;

  // 5. A function return a function as a closure
  // - remember that, returning a function doesn't mean a closure
  // - closure is the object created when inner function capture outer function's variables
  // - 1 closure created = 1 execution of the outer function

  // 1 unique closure object
  auto address1 = makeAdder(99)(100);

  // 1 unique closure object
  auto address2 = makeAdder(200)(100);

  cout << address1 << "-" << address2 << endl;

  // 6. A closure that modify the copied variable within closure from outer function's variables
  // - both phone using the same closure from vn since makePhone is called only 1
  std::string vnCode = "VN";
  auto vn = makePhoneCaptureByValue(vnCode);
  string myFriendPhone = vn(2412341);
  string myMotherPhone = vn(2312412);

  cout << myFriendPhone << endl;
  cout << myMotherPhone << endl;

  // 7. 2 difference closure objected created, not using the same
  std::string enCode = "EN";
  auto vn1 = makePhoneCaptureByValue(vnCode);
  auto en = makePhoneCaptureByValue(enCode);

  string myFriendPhone1 = vn1(2412341);
  string myMotherPhone1 = en(2312412);

  cout << myFriendPhone1 << endl;
  cout << myMotherPhone1 << endl;

  // 8. Capture by reference, only 1 caching sharing the whole time, but still follow the rule of 1 closure object is created per outer's function execution
  // - BUT the numberOfPhone dies after executing the inner function, so closure refernece to the destroy memory
  // - Solution is to use the capture by value + mutable
  auto vn2 = makePhoneCaptureByReference(vnCode);
  string myFriendPhone2 = vn2(2412341);
  string myMotherPhone2 = vn2(2312412);

  cout << myFriendPhone2 << endl;
  cout << myMotherPhone2 << endl;

  // 9. Capture by reference, demonstratig each inner fucntion's execution has its own closure, but since capture by reference is dangerous on dangling reference, the value is unexpected
  auto vn3 = makePhoneCaptureByReference(vnCode);
  auto en2 = makePhoneCaptureByReference(enCode);

  string myFriendPhone3 = vn3(2412341);
  string myMotherPhone3 = en2(2312412);

  cout << myFriendPhone3 << endl;
  cout << myMotherPhone3 << endl;

  // 10. Capture by refernece using smart pointer, maintain the smart pointer, same behavior just like JS or C++

  auto vn4 = makePhoneCaptureByReferenceSmart(vnCode)(2222);
  cout << vn4 << endl;

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