#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int* arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << "index: " << i << ", value: " << arr[i] << endl;
  }
}

/*

Chop the array in half for each iteration
if target > curr, curr's idx++
if target < curr, curr's idx--
if target == curr, return curr;
else return -1

Time Complexity:
- number of remaning N to determine has been decreased over the time N, N/2, N/4, N/ 5
- after k iteration, we gonna leave with only 1 element
--> N/2^k = 1 --> k = log(N) base 2
- For example. if k = 2, meaning number of remaning elements to determine will be
  will be 1000/2^2 = 250


Pre-requisite
- The list must be order

*/
int binarySearch(int* arr, int n, int target) {
  if (n == 0) return -1;
  if (n == 1) return target == arr[0];

  int l = 0;
  int r = n - 1;
  int mid;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);

  // Assume we have 4 ordered array

  int arr1[4] = {1, 3, 4, 5};
  int arr2[2] = {1, 10};
  int arr3[0] = {};
  int arr4[200000] = {1, 3, 4, 5, 0, 0};

  cout << "Find1: " << binarySearch(arr1, 4, 4) << endl;
  cout << "Find2: " << binarySearch(arr2, 2, 10) << endl;
  cout << "Find3: " << binarySearch(arr3, 0, 0) << endl;
  cout << "Find4: " << binarySearch(arr4, 200000, 0) << endl;

  return 0;
}