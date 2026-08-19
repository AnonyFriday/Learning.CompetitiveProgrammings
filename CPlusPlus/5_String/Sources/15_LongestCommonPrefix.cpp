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
#include <vector>
//
using namespace std;

const double E = 1e-8;
const double PI = acos(-1);

std::string findLongestCommonPrefix(vector<string>& list) {
  int N = list.size();

  // first condition
  if (N < 1 || N > 200) return "";

  int firstN = list[0].length();
  if (firstN == 0) return "";

  std::string res = "";

  // get the first string as cavet
  for (int i = 0; i < firstN; i++) {
    char currChar = list[0][i];

    for (int s = 1; s < N; s++) {
      char otherChar = list[s][i];

      // if only 1 do not match
      if (currChar != otherChar) {
        return res;
      }
    }

    // if all are matched
    res.push_back(currChar);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<string> list = {"flower",
                         "flow",
                         "flight"};

  cout << findLongestCommonPrefix(list) << endl;

  vector<string> list1 = {"",
                          "flow",
                          "flight"};

  cout << findLongestCommonPrefix(list1) << endl;

  vector<string> list2 = {"asd",
                          "alow",
                          "flight"};

  cout << findLongestCommonPrefix(list2) << endl;

  return 0;
}