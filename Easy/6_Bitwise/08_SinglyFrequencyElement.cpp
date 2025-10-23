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

// Using unordered_map = dictionary in C#
// inefficient, due to the Space Complexity as n and time complexity as n
int singlyFrequencyElement(const vector<int>& A) {
  unordered_map<int, int> dic;

  for (const int& el : A) {
    dic[el]++;
  }

  for (const pair<int, int>& pair : dic) {
    if (pair.second == 1) return pair.first;
  }

  return -1;
}

// Using cancelling ^, we can attract the only singly remaning element
int singlyFrequencyElement1(const vector<int> A) {
  int result = 0;
  //
  for (const int& el : A) {
    result ^= el;
  }

  return result;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  vector<int> A = {4, 4, 4, 4, 5, 7, 7, 8, 8};
  cout << singlyFrequencyElement(A) << endl;
  cout << singlyFrequencyElement(A) << endl;

  return 0;
}