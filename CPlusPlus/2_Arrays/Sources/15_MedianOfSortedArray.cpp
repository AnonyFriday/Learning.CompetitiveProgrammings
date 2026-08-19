#include <bits/stdc++.h>

using namespace std;

float calculateMedian(int *arr, int n) {
  // if odd, then the middle want
  // if even, then the value in index + 1, and real index - 1
  // then (left + rigth) / 2.0f

  // odd
  if (n % 2 != 0) {
    return *(arr + (int)(n / 2));
  }

  // even
  float mIndex = n / 2.0;
  int leftIndex = mIndex - 1;
  int rightIndex = mIndex;

  return (*(arr + leftIndex) + *(arr + rightIndex)) / 2.0f;
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr1[] = {1, 2, 3, 3, 4, 5};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << calculateMedian(arr1, n1) << "\n";  // 3

  int arr2[] = {1, 4, 5, 5, 6, 7, 8, 9};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << calculateMedian(arr2, n2) << "\n";  // 5

  return 0;
}