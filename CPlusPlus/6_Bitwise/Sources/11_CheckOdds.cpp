#include <bits/stdc++.h>

// #include <algorithm>
// #include <cassert>
// #include <climits>
// #include <cmath>
// #include <cstring>
// #include <iostream>
// #include <list>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <unordered_map>
// #include <vector>
//
using namespace std;

const double E = 1e-8;
const double PI = acos(-1);

/*
1 0000 0001
2 0000 0010
3 0000 0011
4 0000 0100
5 0000 0101

-> as you can see, the last digit is always 1 for odd, 0 or even
-> so if we can extract the right most digit is 1, we can refer it as odd, vice versa

        Time Complexity:
        Space Complexity:

*/

bool isOdd(const int& a) {
  return (a & 1) == 1;
}

bool isEven(const int& a) {
  return (a & 1) == 0;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  int a = 1;
  int b = 2;

  cout << isOdd(a) << endl;
  cout << isEven(b);

  return 0;
}