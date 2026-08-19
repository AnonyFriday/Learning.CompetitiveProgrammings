#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int* arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << "index: " << i << ", value: " << arr[i] << endl;
  }
}

int linearSearch(int* arr, int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) return i;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  srand(time(nullptr));

  int N, target;

  cin >> N >> target;

  int arr[N];

  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 10;
  }

  printArrayCorrect(arr, N);

  cout << "Index: " << linearSearch(arr, N, target);

  return 0;
}