#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    // space
    for (int s = 1; s <= N - i; s++) {
      cout << " ";
    }

    // left
    int val = i;
    for (int l = 1; l <= i; l++) {
      cout << val;
      val++;
    }

    // right
    val -= 2;
    for (int r = 1; r <= i - 1; r++) {
      cout << val;
      val--;
    }

    // endl
    cout << endl;
  }

  return 0;
}