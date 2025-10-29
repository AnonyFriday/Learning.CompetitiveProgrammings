#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  cout << ceil(13.4) << endl;
  cout << ceil(13.6) << endl;

  cout << floor(13.4) << endl;
  cout << floor(13.9) << endl;

  // bitset
  int a = 0;
  int b = -5;

  cout << bitset<8>(a) << " | " << a << endl;
  cout << bitset<8>(~a) << " | " << ~a << endl;

  cout << bitset<8>(b) << " | " << b << endl;
  cout << bitset<8>(~b) << " | " << ~b << endl;

  return 0;
}