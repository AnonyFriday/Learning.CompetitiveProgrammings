#include <bits/stdc++.h>

using namespace std;

/*

        5 rows

        1 row: 10 chars, 65,66,67,68,69,69,68,67,66,65

        2 row: 8 chars,
        65,66,67,68,68,67,66,65

        3 row: 6 chars
        4 row: 4 chars;
        5 row: 2 chars;


        chars = N * 2;
        progress = 'A' + N - r;

*/

void printReverseTriangle(int N) {
  // row
  for (int r = 1; r <= N; r++) {
    char c = 'A';  // start letter
    int cR = c + N - r;
    int cL = c;

    // a,b,c,d,e
    for (; c <= cR; c++) {
      cout << c;
    }

    // e,d,c,b,a
    for (c = c - 1; c >= cL; c--) {
      cout << c;
    }

    // next row;
    cout << endl;
  }
}

/*

AA
ABBA
ABCCBA
ABCDDCBA

*/
void printTriangle(int N) {
  if (N <= 0) return;

  // rows
  for (int i = 1; i <= N; i++) {
    char c = 'A';
    int cL = c + i;
    int cR = c;

    // a,b,c,d
    for (; c < cL; c++) {
      cout << c;
    }

    // d,c,b,a
    for (c = c - 1; c >= cR; c--) {
      cout << c;
    }

    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  printTriangle(N);

  return 0;
}