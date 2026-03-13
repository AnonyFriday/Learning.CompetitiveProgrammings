#include <bits/stdc++.h>

using namespace std;

/*

        Set zeros for rows and cols if appearing 0
        - If seeing zero element, set the first element of that row to be 0 for marking

*/

void setZeros(int (*arr)[4], int rows, int cols) {
  if (rows == 0 || cols == 0) return;

  // avoid filling first row and first cols to zero, using for marking
  bool isFirstRowZero = false;
  bool isFirstColZero = false;

  // rows iteration
  for (int i = 0; i < rows; i++) {
    // marking
    for (int j = 0; j < cols; j++) {
      // if 0 is the original, not from marking
      if (j == 0 && arr[i][j] == 0) {
        isFirstColZero = true;
      }

      // if 0 is the original, not from marking
      if (i == 0 && arr[i][j] == 0) {
        isFirstRowZero = true;
      }

      if (arr[i][j] == 0) {
        arr[i][0] = 0;
        arr[0][j] = 0;
      }
    }
  }

  // filling not first row and first col
  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < cols; j++) {
      if (arr[0][j] == 0 || arr[i][0] == 0) {
        arr[i][j] = 0;
      }
    }
  }

  if (isFirstRowZero) {
    for (int i = 0; i < cols; i++) {
      arr[0][i] = 0;
    }
  }

  if (isFirstColZero) {
    for (int i = 0; i < rows; i++) {
      arr[i][0] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int arr[][4] = {{0, 1, 2, 0},
                  {3, 4, 5, 2},
                  {1, 3, 1, 5}};

  setZeros(&arr[0], 3, 4);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cout << arr[i][j];
    }

    cout << endl;
  }

  return 0;
}