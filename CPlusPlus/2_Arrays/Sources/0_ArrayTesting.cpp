#include <bits/stdc++.h>

using namespace std;

// arr[] and *arr is basically the same
// for the array, we are passing as reference using pointer
// the pointer will point to the first block of memory of the array
void printArray(int arr[]) {
  cout << "In Function 1: " << sizeof(arr) << endl;

  for (int i = 0; i <= sizeof(arr); i++) {
    cout << arr[i] << endl;
  }
}

// not the correct way
void printArray2(int *arr) {
  cout << "In Function 2: " << sizeof(arr) << endl;
  for (int i = 0; i <= sizeof(arr); i++) {
    cout << arr[i] << endl;
  }
}

// correct way
void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

void printArrayInReverse(int *arr, int n) {
  int *lastPtr = arr + n * sizeof(n);

  cout << "In Function 4: " << n << endl;
  for (int i = n - 1; i >= 0; i--) {
    cout << arr[i] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  // Testing Array Initialization
  int a[100];  // array of size 100, filling with unexpected data within the memory

  int b[100] = {0};  // filling all 100 buckets with 0 as a value

  int c[5] = {1, 2, 3};  // filling first three elements are 1,2,3, the rest will be set to

  int d[] = {1, 2, 3};  // optional, the array will automatically define the size of the array

  string fruits[4] = {"apple", "mango", "guava"};

  // Printing the array passing wrong demonstration
  printArray(a);

  // Printing the array passing wrong demonstration
  printArray2(b);

  // Printing the array passing wrong demonstration
  int n = sizeof(c) / sizeof(int);
  printArrayCorrect(c, n);

  // Print the array in the reverse order
  printArrayInReverse(c, n);

  return 0;
}