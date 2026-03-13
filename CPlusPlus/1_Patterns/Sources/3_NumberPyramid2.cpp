#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  if (!(cin >> N) || N < 0) {
    cout << "Invalid";
    return 0;
  }

  for (int r = 1, curr = 1; r <= N; r++) {
    for (int j = 1; j <= r; j++) {
      cout << curr;
      curr++;
    }
    cout << endl;
  }

  return 0;
}