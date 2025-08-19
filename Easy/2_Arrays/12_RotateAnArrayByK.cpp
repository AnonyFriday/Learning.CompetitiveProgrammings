#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

void printArrayCorrect(int* arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << "index: " << i << ", value: " << arr[i] << endl;
  }
}

/*
        Shift element to the right by K
        if k > 0, then (e.g. k = 2, N = 5)
        - i = 0, then shift, (0 + 2) = 2, right
        - i = 0, if k = 7, then (7 + 0) = 0, which > N
        - so we should take module of it, by this technique
                - i = 0,(0 + 7) % 5 = 2, then the final position of i = 0 if  shifting to the right by K is 2


        Performance Testing
        - O(n)

        Space
        - Omega(n)
*/
void rotateByK(int* arr, int n, int k) {
  // normalize k
  k = k % n;

  if (k <= 0 || n <= 1) return;

  int* b = new int[n];

  for (int i = 0; i < n; i++) {
    int newD = (i + k) % n;
    b[newD] = arr[i];
  }

  // copy back the dynamic array to the arr
  for (int i = 0; i < n; i++) {
    arr[i] = b[i];
  }

  // remove the heap array in memory
  delete[] b;
}

/*
        This technique is executed in-place

        Flip the entire array
        Reverse 1th portion of the array [0, k -1]
        Reverse 2sd portion of the array [k, n -1]
*/
void rotateByKUsingReverse(int* arr, int n, int k) {
  // normalize k
  k = k % n;

  if (k <= 0 || n <= 1) return;

  // reverse the entire array
  reverse(arr, arr + n);

  // reverse [0, k - 1]
  reverse(arr, arr + k);

  // reverse [k, n - 1]
  reverse(arr + k, arr + n);
}

int main() {
  ios_base::sync_with_stdio(0);

  srand(time(nullptr));

  int N, k;

  cin >> N >> k;

  int arr[N], b[N];

  for (int i = 0; i < N; i++) {
    arr[i] = i % 10 + 1;
  }

  // copy the array
  std::copy(arr, arr + N, b);

  // print the array of correct
  printArrayCorrect(arr, N);

  // rotate by K
  rotateByK(arr, N, k);
  printArrayCorrect(arr, N);

  // rotate by K using reverse
  printArrayCorrect(b, N);
  rotateByKUsingReverse(b, N, k);

  printArrayCorrect(b, N);

  return 0;
}
