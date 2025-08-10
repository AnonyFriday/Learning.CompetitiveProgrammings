#include <bits/stdc++.h>

using namespace std;

/*
        n = a x b
        if n = 24,
        then if
                a = 24, b = 1
                a = 12, b = 2
                a = 8, b = 3
                a = 6, b = 4
                a = 5, b = 5 --> cannot be since a x b > 24,
                             --> a = 6, b = 4 is the max
                a = 6, b = 4 --> as you can see, the more we reach, the more it overlap from the start
                                 then we can see the bound is a <= sqrt(n)
*/

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  if (N == 1 || N <= 0 || N % 2 == 0 || N % 3 == 0) {
    cout << "Is not prime.";
    return 0;
  }

  for (int i = 2; i <= sqrt(N); i++) {
    if (N % i == 0) {
      cout << "Is not prime.";
      return 0;
    }
  }

  cout << "Is a prime.";

  return 0;
}