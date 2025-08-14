#include <bits/stdc++.h>
#include <math.h>

using namespace std;

/*

  n! ~ căn(2*pi*n)*(n/e)^n

*/
long double sol_1_stirling(int n) {
  // 0! = 1
  if (n == 0 || n == 1) return 1;

  // cos(pi) = -1
  const double pi = acos(-1.0);
  return sqrt(2 * pi * n) * pow(n / exp(1.0), n);
}

int main() {
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  cout << "! ~: " << sol_1_stirling(n) << endl;

  // using tgamma(a + 1) to calculate the exact value
  cout << "Exact: " << (long double)tgamma(n + 1) << endl;

  return 0;
}