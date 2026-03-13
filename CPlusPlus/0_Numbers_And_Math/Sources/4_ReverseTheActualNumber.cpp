#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int N, result;
  cin >> N;

  // 1234
  // 4: 4  = answer * 10 + 4 = 0 + 4
  // 3: 43 = answer * 10 + 3 = 43
  // 2: 432 = answer * 10 + 2 = 430 + 2 = 432

  while (N != 0) {
    int last_digit = N % 10;
    result = result * 10 + last_digit;

    N /= 10;
  }

  cout << result;

  return 0;
}