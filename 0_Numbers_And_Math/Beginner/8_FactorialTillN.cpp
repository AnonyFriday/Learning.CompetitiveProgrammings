#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int N;

  if (!(cin >> N) || N <= 0) {
    cout << "Invalid!";
    return 0;
  }

  // base 1
  if (N == 1) {
    cout << 1;
    return 0;
  }

  bool isPrime = true;

  // from 2 to N
  for (int i = 2; i <= N; i++) {
    // from 2 upto sqrt of the current i number
    isPrime = true;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      cout << i << " ";
    }
  }

  return 0;
}