#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

/*

        Using nC2 to  all subarrays with [i,j]
        Plus N if i == j

        nC2 = n! / 2! * (n-2)!
            = n * (n-1) * (n-2)! / 2! * (n-2)!
            = n * (n-1) / 2
        count = nC2 + n
                 = n (n+1) / 2

*/
int countDistinctSize2SubArrays(int *arr, int n) {
  int count = 0;

  count = n * (n + 1) / 2;

  return count;
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  int arr[N];

  for (int i = 0; i < N; i++) {
    arr[i] = i;
  }

  int n = sizeof(arr) / sizeof(int);

  printArrayCorrect(arr, n);

  cout << "Count: " << countDistinctSize2SubArrays(arr, n) << endl;

  // how many elemenet: i
  for (int i = 0; i < n; i++) {
    // how many pair of
    for (int j = i; j < n; j++) {
      // sub array
      for (int k = i; k <= j; k++) {
        cout << arr[k] << ",";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}