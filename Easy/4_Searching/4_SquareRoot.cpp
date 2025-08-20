#include <bits/stdc++.h>

using namespace std;

/*

Consider the n is the perfect square number (not something like 48, 47, ...)

*/
int sqrtRoot(int n) {
  if (n == 0 || n == 1) return n;

  int l = 1, r = n;
  long long int mid;
  long long int sqr;
  while (l <= r) {
    mid = l + (r - l) / 2;
    sqr = mid * mid;

    if (sqr == n) {
      return mid;
    } else if (sqr > n) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);

  int n;

  if (!(cin >> n)) {
    cout << "Invalid Input";
  }

  cout << sqrtRoot(n);

  return 0;
}
