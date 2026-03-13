#include <bits/stdc++.h>

using namespace std;

int checkProductSign(int (*arr)[5], int n, int m) {
  int negCount = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int el = arr[i][j];

      if (el == 0) return 1;
      if (el < 0) negCount++;
    }
  }

  return (negCount % 2 == 0) ? 1 : 0;
}

int main() {
  ios_base::sync_with_stdio(0);

  int matrix[4][5] = {
      {1, 1, 1, 1, 10},
      {2, 2, 2, 2, 10},
      {3, 3, 3, 1, 10},
      {4, 4, 4, 4, 10}};

  cout << checkProductSign(&matrix[0], 4, 5);

  return 0;
}