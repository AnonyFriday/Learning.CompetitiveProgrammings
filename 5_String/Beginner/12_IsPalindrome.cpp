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

bool isPalindrome(string &s) {
  if (s.size() == 0 || s.size() == 1) return true;

  int i = 0;
  int j = s.size() - 1;

  while (i <= j) {
    if (!isalnum(s[i]) && !isalnum(s[j])) {
      i++;
      j--;
      continue;
    }

    if (!isalnum(s[i])) {
      i++;
      continue;
    }

    if (!isalnum(s[j])) {
      j--;
      continue;
    }

    if (tolower(s[i]) != tolower(s[j])) return false;

    i++;
    j--;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);

  string s;
  getline(cin, s);

  std::cout << isPalindrome(s);

  return 0;
}