#include <bits/stdc++.h>

using namespace std;

void swap(int &l, int &r) {
  int *temp = &l;
  l = r;
  r = *temp;
}

void reverseAnArrayInPlace(int *arr, int n) {
  int l = 0;
  int r = n - 1;

  while (l < r) {
    swap(arr[l], arr[r]);
    l++;
    r--;
  }
}

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }

  printArrayCorrect(arr, n);

  reverseAnArrayInPlace(arr, n);

  printArrayCorrect(arr, n);

  return 0;
}