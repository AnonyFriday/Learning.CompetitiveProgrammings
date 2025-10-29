#include <bits/stdc++.h>

using namespace std;

/*

        Traditional method

*/
int gcdNormal(int x, int y) {
  // implement your code here

  if (x == y) return x;
  if (x == 0) return y;
  if (y == 0) return x;

  int min = x > y ? y : x;
  int result = 1;

  for (int i = 1; i <= min; i++) {
    if (x % i == 0 && y % i == 0) {
      result = i;
    }
  }

  return result;
}

/*

        gcd(a, b) = gcd(b, a - b)

*/
int gcdAdvance(int x, int y) {
  if (x == 0 && y != 0) return y;
  if (y == 0 && x != 0) return x;

  // continue until the x == y, which is the gcd of both number

  while (x != y) {
    if (x > y) {
      x = x - y;
    } else {
      y = y - x;
    }
  }

  return x;
}

/*

        gcd(a,b) = (b, a mod b)

*/
int gcdAdvance2(int x, int y) {
  if (x == 0 && y != 0) return y;
  if (y == 0 && x != 0) return x;

  // gcd(4,0) reaches, then stop
  while (x != 0 && y != 0) {
    if (x > y) {
      x %= y;
    } else {
      y %= x;
    }
  }

  return x == 0 ? y : x;
}

/*

        Main function here

*/
int main() {
  ios_base::sync_with_stdio(0);

  // Using GCD
  cout << gcdNormal(4, 0) << endl;
  cout << gcdAdvance(12, 16) << endl;
  cout << gcdNormal(4, 1) << endl
       << endl;

  // Using GCD advanced
  cout << gcdAdvance(4, 0) << endl;
  cout << gcdAdvance(12, 24) << endl;
  cout << gcdAdvance(5, 7) << endl;
  cout << gcdAdvance(4, 1) << endl
       << endl;

  // Using GCD advanced2
  cout << gcdAdvance2(4, 0) << endl;
  cout << gcdAdvance2(12, 24) << endl;
  cout << gcdAdvance2(12, 16) << endl;
  cout << gcdAdvance2(4, 1) << endl
       << endl;

  return 0;
}