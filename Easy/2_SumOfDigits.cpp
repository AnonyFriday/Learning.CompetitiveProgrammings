#include <bits/stdc++.h>

using namespace std;

/*
        Sum of its digits;
*/
int main() {
  ios_base::sync_with_stdio(0);

  int n;
  int sum;
  cin >> n;

  if (n < 0) {
    n = -n;
  }

  while (n != 0) {
    int d = n % 10;
    n /= 10;
    sum += d;
  }

  cout << sum;

  return 0;
}