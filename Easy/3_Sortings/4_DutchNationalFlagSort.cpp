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

Dutch National Flag problem
- Sort an array into 3 distinct regions
- in-place (sort on the original array)
- Performance: O(n)

Solution
- using 3 pointers represents for 3 barriers: start, mid, end
- looping until the mid >= end

*/
void sortOnSet(int *arr, int n) {
  if (n == 0 || n == 1) return;

  int start = 0,
      end = n - 1,
      mid = 0;

  // case 2: 2, swap end with start, end--;
  // case 1: 1, mid++
  // case 0: 0, swap mid with start, start++
  while (mid <= end) {
    const int el = arr[mid];

    switch (el) {
      case 0: {
        swap(arr[start], arr[mid]);
        start++;
        mid++;
        break;
      }
      case 1: {
        mid++;
        break;
      }
      case 2: {
        swap(arr[end], arr[mid]);
        end--;
        break;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[6] = {1, 2, 0, 0, 1, 2};
  int arr2[2] = {1, 0};
  int arr3[0] = {};
  int arr4[5] = {0, 0, 0, 0, 0};

  sortOnSet(arr1, 6);
  printArrayCorrect(arr1, 6);

  sortOnSet(arr2, 2);
  printArrayCorrect(arr2, 2);

  sortOnSet(arr3, 0);
  printArrayCorrect(arr3, 0);

  sortOnSet(arr4, 5);
  printArrayCorrect(arr4, 5);

  return 0;
}