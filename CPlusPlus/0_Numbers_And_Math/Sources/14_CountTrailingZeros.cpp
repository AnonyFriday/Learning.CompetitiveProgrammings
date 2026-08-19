#include <bits/stdc++.h>

using namespace std;

int countTrailingZeros(int num) {
  if (num == 0) return 1;  // 0 only has 1 trailing zero

  int count = 0;

  while (num > 0) {
    int d = num % 10;

    if (d != 0) {
      break;
    }

    count++;
    num /= 10;
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;

  if (!(cin >> N) || N <= 0)
    return 0;

  cout << countTrailingZeros(N);

  return 0;
}