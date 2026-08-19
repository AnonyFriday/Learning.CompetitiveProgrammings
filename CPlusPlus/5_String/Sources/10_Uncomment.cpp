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

void uncomment(string &s) {
  if (s.size() == 0) return;

  int left = s.find("/*");
  int right = s.find("*/");

  if (left == std::string::npos || right == std::string::npos || left + 2 >= right) {
    return;
  }

  left += 2;
  s = s.substr(left, right - left);
}

int main() {
  ios_base::sync_with_stdio(0);

  string code = "/* hello world */";
  uncomment(code);

  cout << code << endl;

  return 0;
}