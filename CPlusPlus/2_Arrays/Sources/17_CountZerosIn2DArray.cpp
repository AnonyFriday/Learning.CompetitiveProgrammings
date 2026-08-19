#include <bits/stdc++.h>

using namespace std;

/*

        The array is not sorted
        - Simply using 2 iterations, cuz if binary search would be nice on the sorted array
*/

int countZeros(int (*arr)[5], int n, int m) {
  if (n == 0 || m == 0) return -1;

  int cnt = 0;
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c)
      cnt += (arr[r][c] == 0);
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);

  int matrix[4][5] = {
      {1, 0, 0, 0, 0},
      {0, 0, 0, 0, 1},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0}};

  cout << countZeros(&matrix[0], 4, 5);

  return 0;
}