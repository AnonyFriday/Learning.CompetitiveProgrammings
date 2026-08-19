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

/*

        5 10 -2 -4
                 i
        j

*/
void selectionSort(int *arr, int n) {
  if (n == 0 || n == 1) return;

  int maxIndex;

  for (int i = n - 1; i > 0; i--) {
    maxIndex = i;
    for (int j = 0; j < i; j++) {
      if (arr[maxIndex] < arr[j]) {
        maxIndex = j;
      }
    }

    // if equals, which mean no swapping, then current i is correct
    if (i != maxIndex)
      swap(arr[i], arr[maxIndex]);
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[4] = {5, 10, -4, -2};
  int arr2[2] = {10, 1};
  int arr3[0] = {};
  int arr4[5] = {2, 2, 2, 2, 2};

  selectionSort(arr1, 4);
  printArrayCorrect(arr1, 4);

  selectionSort(arr2, 2);
  printArrayCorrect(arr2, 2);

  selectionSort(arr3, 0);
  printArrayCorrect(arr3, 0);

  selectionSort(arr4, 5);
  printArrayCorrect(arr4, 5);

  return 0;
}