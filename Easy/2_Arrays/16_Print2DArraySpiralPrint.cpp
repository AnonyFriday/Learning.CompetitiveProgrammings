#include <bits/stdc++.h>

using namespace std;

/*

Printing
- first row
- end column
- end row
- start col

After printing the first pass, now we move the pointer
- startRow++;
- endRow--;
- startCol++;
- endCol--;

*/

void printSpiralPrint(int (*arr)[5], int n, int m) {
  // 4 variablesa
  int startRow = 0;
  int endRow = n - 1;
  int startCol = 0;
  int endCol = m - 1;

  // loop for the spiral array
  while (startRow <= endRow && startCol <= endCol) {
    // start row
    for (int i = startCol; i <= endCol; i++) {
      cout << arr[startRow][i] << " ";
    }

    // end col
    for (int i = startRow + 1; i <= endRow; i++) {
      cout << arr[i][endCol] << " ";
    }

    // end row
    for (int i = endCol - 1; i >= startCol; i--) {
      cout << arr[endRow][i] << " ";
    }

    // start col
    for (int i = endRow - 1; i >= startRow + 1; i--) {
      cout << arr[i][startCol] << " ";
    }

    startRow++;
    endRow--;
    startCol++;
    endCol--;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int matrix[4][5] = {
      {1, 1, 1, 1, 10},
      {2, 2, 2, 2, 10},
      {3, 3, 3, 3, 10},
      {4, 4, 4, 4, 10}};

  printSpiralPrint(&matrix[0], 4, 5);

  return 0;
}