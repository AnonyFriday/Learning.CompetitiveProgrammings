#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

bool customComp(int a, int b) {
  return a > b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  // seed the rand
  srand(time(nullptr));

  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    arr[i] = (rand() % 50 + 1);
  }

  printArrayCorrect(arr, n);

  // use built in sort function
  sort(arr, arr + n, customComp);

  printArrayCorrect(arr, n);

  return 0;
}