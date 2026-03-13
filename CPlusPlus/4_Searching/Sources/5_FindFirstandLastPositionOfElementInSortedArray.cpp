#include <bits/stdc++.h>

using namespace std;

/*

        5,5,5,5,5,5,5

        1,2,3,5,5,5,5,5,6,7,8

*/

int binarySearch(const int *arr, int n, int target, bool isSearchingLeft) {
  if (n == 0) return -1;
  if (n == 1) return 0;

  int l = 0, r = n - 1, mid;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (arr[mid] == target) {
      // case mid == 0
      if (mid == 0) return 0;
      if (mid == n - 1) return n - 1;

      if (isSearchingLeft) {
        // case 1,5 <-- ,5,6 for left
        if (mid > 0 && arr[mid] == target && arr[mid - 1] != target) {
          return mid;
        } else {
          r = mid - 1;
        }
      } else {
        // case 1,5,5 <--,6 for right
        if (mid < n - 1 && arr[mid] == target && arr[mid + 1] != target) {
          return mid;
        } else {
          l = mid + 1;
        }
      }

      // case for no equals to target
    } else if (arr[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

/*
        Optimize the logic

*/
int binarySearch2(const int *arr, int n, int target, bool isSearchingLeft) {
  if (n == 0) return -1;
  if (n == 1) return target == arr[0] ? 0 : -1;

  int l = 0, r = n - 1, ans = -1, mid;

  while (l <= r) {
    mid = l + ((r - l) >> 1);

    if (arr[mid] == target) {
      // case mid == 0
      if (mid == 0) return 0;
      if (mid == n - 1) return n - 1;

      // keep searching on left and on right until mid = target
      ans = mid;
      if (isSearchingLeft) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }

      // case for no equals to target
    } else if (arr[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return ans;
}

/*

Using equal_range

*/

pair<int, int> firstAndLastOccurence(const int *arr, int n, int tar) {
  if (n == 0 || arr == nullptr) return {-1, -1};

  // 1,2,3,5,5,5,5,5,6,7,8 --> case in middle
  // 5,5,5,5,5,6,7,8       --> case wall left
  // 1,2,3,5,5,5,5,5       --> case wall right

  int left = binarySearch2(arr, n, tar, true);
  if (left == -1) return {-1, -1};

  int right = binarySearch2(arr, n, tar, false);

  return {left, right};
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[] = {0, 5, 5, 5, 6, 7};
  int arr2[] = {5, 6, 7, 8, 9, 10};
  int arr3[] = {1, 2, 3, 4, 5, 5};
  const int *arr4 = nullptr;  // empty
  int arr5[] = {1, 2, 3, 4, 6, 7};

  auto p1 = firstAndLastOccurence(arr1, 6, 5);
  auto p2 = firstAndLastOccurence(arr2, 6, 5);
  auto p3 = firstAndLastOccurence(arr3, 6, 5);
  auto p4 = firstAndLastOccurence(arr4, 0, 5);
  auto p5 = firstAndLastOccurence(arr5, 6, 5);

  cout << "Find1: " << p1.first << ' ' << p1.second << '\n';
  cout << "Find2: " << p2.first << ' ' << p2.second << '\n';
  cout << "Find3: " << p3.first << ' ' << p3.second << '\n';
  cout << "Find4: " << p4.first << ' ' << p4.second << '\n';
  cout << "Find5: " << p5.first << ' ' << p5.second << '\n';

  return 0;
}