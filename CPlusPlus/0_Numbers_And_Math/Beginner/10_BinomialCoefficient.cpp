#include <bits/stdc++.h>

using namespace std;

// factorial
int fac(int n) {
  if (n == 1 || n == 0) return 1;

  int exp = 1;

  for (int i = 2; i <= n; i++) {
    exp *= i;
  }

  return exp;
}

// calculate binomial coefficient
int binCoeff(int N, int C) {
  // exceltional case
  if (C == 0) return 1;
  if (C == 1) return N;
  if (N == C) return 1;

  int ans = fac(N) / (fac(C) * fac(N - C));

  return ans;
}

// main
int main() {
  ios_base::sync_with_stdio(0);

  int N, C;

  if (!(cin >> N >> C) || N < 0 || C < 0) {
    cout << "Invalid";
    return 0;
  }

  int ans = binCoeff(N, C);

  cout << ans;

  return 0;
}