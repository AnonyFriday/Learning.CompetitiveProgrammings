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

int frequencyOfLargestElement(int* arr, int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  int l = 0;
  int r = n - 1;
  int target = r;
  int mid;

  // exception in case of 2,2,2,2,2,2,2
  if (arr[l] == arr[target]) return target - l + 1;

  while (l <= r) {
    mid = l + (r - l) / 2;

    // Find the first occurence of 5, meaning the lowest
    // occurence index of 5

    // 1,2,3,4,5,5,5,5,5,5,5,5,5
    // 0,1,2,3,4,5,6,7,8,9,10,11,12
    // l                          r   mid = 6
    // l         r                    mid = 2
    //       l   r                    mid = 4
    //         l r                    mid = 4
    //        l,r                     mid = 4 --> return 4
    // frequency = 12 - 4 + 1 = 9

    if (arr[mid] < arr[target]) {
      l = mid + 1;
    }

    // in the range of 5s
    else if (arr[mid] == arr[target]) {
      // 1,2,3,4,5,5,5
      //           m
      if (mid > 0 && arr[mid - 1] == arr[target]) {
        r = mid - 1;
      }

      // 1,2,3,4,5,5,5
      //       m
      else if (mid > 0 && arr[mid - 1] != arr[target]) {
        return target - mid + 1;
      }

    } else {
      r = mid - 1;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[5] = {1, 3, 3, 3, 3};
  int arr2[2] = {1, 10};
  int arr3[0] = {};
  int arr4[9] = {1, 2, 3, 7, 7, 7, 7, 7, 7};

  cout << "Find1: " << frequencyOfLargestElement(arr1, 5) << endl;
  cout << "Find2: " << frequencyOfLargestElement(arr2, 2) << endl;
  cout << "Find3: " << frequencyOfLargestElement(arr3, 0) << endl;
  cout << "Find4: " << frequencyOfLargestElement(arr4, 9) << endl;

  return 0;
}