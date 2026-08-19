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

int canBeFormedOrNot(string s1, string s2) {
  if (s1.size() == 0 || s2.size() == 0) return 0;

  // create a pool of chars
  int pool[26] = {0};

  for (char c : s1) {
    pool[c - 'a'] += 1;
  }

  for (char c : s2) {
    // minus this char from the pool
    // if < 0, meaning no more char left from the pool
    if (--pool[c - 'a'] < 0) {
      return 0;
    }
  }

  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);

  string s;
  getline(cin, s);

  cout << canBeFormedOrNot("softwaredevelopmentengineer", "developer") << endl;
  cout << canBeFormedOrNot("helloworld", "worry") << endl;

  return 0;
}