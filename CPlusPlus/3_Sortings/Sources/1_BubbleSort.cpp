#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << "index: " << i << ", value: " << arr[i] << endl;
  }
}

void swap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

void bubbleSort(int *arr, int n) {
  if (n == 0 || n == 1) return;

  // flag, incase no swapping happen, then the array is sorted
  bool isSorted = true;

  // ascending
  // 3 5 6 1
  // i
  // j

  for (int i = 0; i < n - 1; i++) {
    isSorted = true;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] >= arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSorted = false;
      }
    }

    if (isSorted) return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[4] = {5, 10, -4, -2};
  int arr2[2] = {10, 1};
  int arr3[0] = {};
  int arr4[5] = {2, 2, 2, 2, 2};

  bubbleSort(arr1, 4);
  printArrayCorrect(arr1, 4);

  bubbleSort(arr2, 2);
  printArrayCorrect(arr2, 2);

  bubbleSort(arr3, 0);
  printArrayCorrect(arr3, 0);

  bubbleSort(arr4, 5);
  printArrayCorrect(arr4, 5);

  return 0;
}
