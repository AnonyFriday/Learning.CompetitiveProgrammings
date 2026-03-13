#include <bits/stdc++.h>

using namespace std;

/*

n x m

*/
void printWaveLength(int* arr, int rs, int cs) {
  if (rs == 0 || cs == 0) return;

  // loop over the columns
  for (int col = 0; col < cs; col++) {
    // if odd, then print from top to bottom
    if (col % 2 == 0) {
      for (int row = 0; row < rs; row++) {
        cout << *(arr + row * cs + col) << " ";
      }
      cout << endl;
    }

    // if even, the print from bottom up to top
    else {
      for (int row = rs - 1; row >= 0; row--) {
        cout << *(arr + row * cs + col) << " ";
      }
      cout << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int matrix[4][4] = {
      {1, 1, 1, 1},
      {2, 2, 2, 2},
      {3, 3, 3, 3},
      {4, 4, 4, 4}};

  printWaveLength(&matrix[0][0], 4, 4);

  return 0;
}