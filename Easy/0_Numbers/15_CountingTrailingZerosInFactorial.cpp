#include <bits/stdc++.h>

using namespace std;

/*
 Counting Trailing Zeros in Factorial
 by counti number of 5s

*/
int countTrailingZerosInFactorial(int num) {
  // 0! = 1 --> no trailing 0s
  if (num == 0) return 0;

  int count = 0;
  while (num > 0) {
    num = num / 5;  // n/5 + n/5^2 + n/5^3, ...
    count += floor(num);
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;

  if (!(cin >> N) || N <= 0)
    return 0;

  cout << countTrailingZerosInFactorial(N);

  return 0;
}