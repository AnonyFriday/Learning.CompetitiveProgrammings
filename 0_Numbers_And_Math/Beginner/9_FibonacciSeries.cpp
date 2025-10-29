#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  unsigned long long int N;

  // check null or N < 0
  if (!(cin >> N) || N < 0) {
    cout << "Invalid N\n";
    return 0;
  }

  // 0 1 2 3 4 5
  // 0 1 1 2 3 5

  // base case of value
  unsigned long long prev = 0;  // f(0) = 0
  unsigned long long curr = 1;  // f(1) = 1
  unsigned long long next = 0;

  for (unsigned long long i = 0; i <= N; i++) {
    if (i == 0) {
      cout << prev;
    } else if (i == 1) {
      cout << " " << curr;
    } else {
      next = prev + curr;
      cout << " " << next;
      prev = curr;
      curr = next;
    }
  }
  return 0;
}