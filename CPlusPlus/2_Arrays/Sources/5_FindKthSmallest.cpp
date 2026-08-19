#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int kthSmallest(int A[], int k, int sizeOfArray) {
  sort(A, A + sizeOfArray);
  return A[k - 1];  // K is index-base 1
}

int kthSmallestWithoutFullySort(int A[], int k, int sizeOfArray) {
  nth_element(A, A + (k - 1), A + sizeOfArray);
  return A[k - 1];
}

int main() {
  int arr[] = {7, 10, 4, 3, 20, 15};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;
  cout << kthSmallest(arr, k, n) << "\n";  // 7
  cout << kthSmallestWithoutFullySort(arr, k, n) << "\n";
}
