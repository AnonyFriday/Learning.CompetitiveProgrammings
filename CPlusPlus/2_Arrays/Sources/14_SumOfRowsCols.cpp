#include <bits/stdc++.h>

#define MAX_N 100
using namespace std;

// in c/c++, 2d arrays are treated as teh continous block n*n 1d array
void printRowColSums(int *a, int n) {
  if (n == 0) return;

  int rows[MAX_N] = {0};
  int cols[MAX_N] = {0};

  // as you can see, we need to loop at least n*n for each cell of the matrix, consider flatten the array
  // better way to loop it in 1 pass
  // calculate the index for each pass
  // cols spans from 0 - 3
  // rows spans from
  // - 0-3: 0
  // - 4-7: 1
  // - 7-11: 2
  // - 12-15: 3

  int nn = n * n;

  for (int i = 0; i < nn; i++) {
    int c = i % n;
    int r = i / n;
    rows[r] += a[i];
    cols[c] += a[i];
  }

  // row sums
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << rows[i];
  }
  cout << '\n';

  // column sums
  for (int j = 0; j < n; ++j) {
    if (j) cout << ' ';
    cout << cols[j];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);

  int matrix[4][4] = {
      {1, 1, 1, 1},
      {2, 2, 2, 2},
      {3, 3, 3, 3},
      {4, 4, 4, 4}};

  int n = 4;

  // matrix = &matrix[0], meaning a pointer to the first row
  // &matrix[0], meaning a pointer to the first rpw
  // &matrix[0][0], meaning a pointer to the first cell = the entire 2d array

  printRowColSums(&matrix[0][0], n);

  return 0;
}