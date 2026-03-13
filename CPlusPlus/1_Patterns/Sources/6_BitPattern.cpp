#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  if (!(cin >> N) || N <= 0) {
    cout << "Invalid!";
    return 0;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      // odd position -> 1 then 0
      if (
          (i % 2 == 1 && j % 2 == 1) ||
          (i % 2 == 0 && j % 2 == 0)) {
        cout << 1;
      } else {
        cout << 0;
      }
    }

    cout << endl;
  }

  return 0;
}