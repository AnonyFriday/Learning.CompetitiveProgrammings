#include <bits/stdc++.h>

using namespace std;

/*
total: 5
1 row: 1 star, 4 space
2 row: 3 star, 3 space
3 row: 5 star, 2 space
4 row: 7 star, 1 space
5 row: 9 star, 0 space

*/
int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  // rows
  for (int r = 1; r <= N; r++) {
    // space
    for (int i = 1; i <= N - r; i++) {
      cout << " ";
    }

    // star
    for (int i = 1; i <= r * 2 - 1; i++) {
      cout << "*";
    }

    // next row
    cout << endl;
  }

  return 0;
}