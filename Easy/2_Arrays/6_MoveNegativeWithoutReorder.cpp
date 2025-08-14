#include <bits/stdc++.h>

using namespace std;

void moveNegativesToEnd(int *arr, int n) {
  int posArr[n];
  int negArr[n];

  int posCount = 0, negCount = 0;

  // put to the right signed bucket
  for (int i = 0; i < n; i++) {
    int el = arr[i];
    if (el >= 0) {
      posArr[posCount++] = el;
    } else {
      negArr[negCount++] = el;
    }
  }

  int idx = 0;
  // positive
  for (int i = 0; i < posCount; i++) {
    arr[idx++] = posArr[i];
  }

  // negative
  for (int i = 0; i < negCount; i++) {
    arr[idx++] = negArr[i];
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  moveNegativesToEnd(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}