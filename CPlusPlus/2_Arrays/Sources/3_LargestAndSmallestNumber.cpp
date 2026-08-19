#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

/*
        Return a pair
*/
pair<int, int> findLargestAndSmallest(int *arr, int n) {
  pair<int, int> pair;

  int max = INT_MIN;
  int min = INT_MAX;

  for (int i = 0; i < n; i++) {
    int el = arr[i];
    if (el >= max) max = el;
    if (el <= min) min = el;
  }

  return make_pair(max, min);
}

int main() {
  ios_base::sync_with_stdio(0);

  // seed the rand
  srand(time(nullptr));

  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    arr[i] = (rand() % 50 + 1);
  }

  printArrayCorrect(arr, n);

  return 0;
}