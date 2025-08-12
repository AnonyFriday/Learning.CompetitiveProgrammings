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

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  // row
  for (int r = 1; r <= N; r++) {
    char c = 'A';
    int cR = c + N - r;
    int cL = c;

    // a,b,c,d,e
    for (; c <= cR; c++) {
      cout << c;
    }

    // // e,d,c,b,a
    for (c = c - 1; c >= cL; c--) {
      cout << c;
    }

    // next row;
    cout << endl;
  }

  return 0;
}