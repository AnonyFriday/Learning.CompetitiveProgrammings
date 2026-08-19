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

bool isSubsequent(const string& str1, const string& str2) {
  // every string contains ''
  if (str1.length() < 0) return true;
  if (str2.length() < 0) return false;

  int len1 = str1.length();
  int len2 = str2.length();

  int curr1 = 0;
  int curr2 = 0;

  while (curr1 < len1 && curr2 < len2) {
    // matching char in str1 in str2 will increase the pointer
    if (str1[curr1] == str2[curr2]) {
      curr1++;
    }

    curr2++;
  }

  if (curr1 == len1) return true;
  return false;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  string str1;
  string str2;

  getline(cin, str1);
  getline(cin, str2);

  cout << isSubsequent(str1, str2) << endl;

  return 0;
}