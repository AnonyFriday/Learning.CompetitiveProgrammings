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

// sorting in ascending order
void insertionSort(int *arr, int n) {
  if (n == 0 || n == 1) return;

  // unsorted part
  for (int i = 1; i < n; i++) {
    int pickedVal = arr[i];
    // moving foward until picked's value < i's value

    int j = i;
    while (j > 0 && (arr[j - 1] > pickedVal)) {
      arr[j] = arr[j - 1];
      j--;
    }

    // when reaching suitable slot, assign picked to that slot
    arr[j] = pickedVal;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[4] = {5, 10, -4, -999};
  int arr2[2] = {10, 1};
  int arr3[0] = {};
  int arr4[5] = {2, 2, 2, 2, 2};

  insertionSort(arr1, 4);
  printArrayCorrect(arr1, 4);

  insertionSort(arr2, 2);
  printArrayCorrect(arr2, 2);

  insertionSort(arr3, 0);
  printArrayCorrect(arr3, 0);

  insertionSort(arr4, 5);
  printArrayCorrect(arr4, 5);

  return 0;
}