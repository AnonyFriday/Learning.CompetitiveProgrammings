#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

int finKFrequency(int *arr, int n, int target) {
  if (n == 0) return 0;

  int count = 0;

  for (int i = 0; i < n; i++) {
    if (target == *(arr + i)) {
      count++;
    }
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(0);
  srand(time(nullptr));

  int N;

  cin >> N;

  int arr[N];

  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 10 + 1;
  }

  printArrayCorrect(arr, N);
  cout << "Count: " << finKFrequency(arr, N, 2);

  return 0;
}