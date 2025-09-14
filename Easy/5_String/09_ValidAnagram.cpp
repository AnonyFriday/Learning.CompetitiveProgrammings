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

using namespace std;

const double E = 1e-8;
const double PI = acos(-1);

bool isAnagram(string& s, string& t) {
  int x = 0;

  // using a ^ a = 0 bitwise operation

  for (const int& a : s) {
    x ^= a;
  }

  for (const int& b : t) {
    x ^= b;
  }

  return x == 0;
}

int main() {
  ios_base::sync_with_stdio(0);

  string s, t;

  getline(std::cin, s);
  getline(std::cin, t);

  cout << "Is Anagram: " << isAnagram(s, t);

  return 0;
}
