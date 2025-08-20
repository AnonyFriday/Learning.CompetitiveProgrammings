#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int* arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << "index: " << i << ", value: " << arr[i] << endl;
  }
}

/*

The array is sorted
Using binary search, to determince the lower bound
Number of frequency = upper index - lowerindex + 1

*/

int frequencyOfLargestOnes(int* arr, int n) {
  if (n == 0) return 0;

  // 1 element
  if (n == 1 && arr[0] == 1) return 1;
  if (n == 1 && arr[0] == 0) return 0;

  // exception in case of 1,1,1,1,1,1,1
  if (arr[0] == 1 && arr[n - 1] == 1) return n;

  int l = 0;
  int r = n - 1;
  int targetVal = 1;
  int mid;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (arr[mid] < targetVal) {
      l = mid + 1;
    }

    // in the range of 1s
    else if (arr[mid] == targetVal) {
      // 0,0,0,0,1,1,1
      //           m
      if (mid > 0 && arr[mid - 1] == targetVal) {
        r = mid - 1;
      }

      // 0,0,0,0,1,1,1
      //       m
      else if (mid > 0 && arr[mid - 1] != targetVal) {
        return (n - 1) - mid + 1;
      }

    } else {
      r = mid - 1;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[5] = {0, 0, 0, 1, 1};
  int arr2[2] = {0, 0};
  int arr3[0] = {};
  int arr4[9] = {0, 0, 0, 1, 1, 1, 1, 1, 1};

  cout << "Find1: " << frequencyOfLargestOnes(arr1, 5) << endl;
  cout << "Find2: " << frequencyOfLargestOnes(arr2, 2) << endl;
  cout << "Find3: " << frequencyOfLargestOnes(arr3, 0) << endl;
  cout << "Find4: " << frequencyOfLargestOnes(arr4, 9) << endl;

  return 0;
}