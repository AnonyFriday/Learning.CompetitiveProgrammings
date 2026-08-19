#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  // print the last digit
  while (N > 0) {
    int last_digit = N % 10;
    cout << last_digit;
    N /= 10;
  }

  return 0;
}