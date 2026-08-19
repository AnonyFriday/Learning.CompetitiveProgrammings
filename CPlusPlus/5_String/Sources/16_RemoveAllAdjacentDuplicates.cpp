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

std::string stackToString(std::stack<char>& s) {
  std::vector<char> temp_vec;

  temp_vec.reserve(s.size());

  while (!s.empty()) {
    temp_vec.push_back(s.top());
    s.pop();
  }

  std::reverse(temp_vec.begin(), temp_vec.end());
  return std::string(temp_vec.begin(), temp_vec.end());
}

string removeAllAdjacent(const string& str) {
  int N = str.length();

  if (N < 1 || N > 105) return str;

  std::stack<char> result;

  // loop through all chars
  for (const char& c : str) {
    // if stack is empty, add into it
    if (result.size() == 0) {
      result.push(c);
    } else {
      char curr = result.top();
      if (curr == c) {
        result.pop();
      } else {
        result.push(c);
      }
    }
  }

  return stackToString(result);
}

string removeAllAdjacentString(const string& str) {
  int N = str.length();

  if (N < 1 || N > 105) return str;

  std::string result = "";

  for (const char& c : str) {
    if (result.empty() || c != result.back()) {
      result.push_back(c);
    } else {
      result.pop_back();
    }
  }

  return result;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  string str1 = "abbacazxc";

  cout << removeAllAdjacent(str1) << endl;
  cout << removeAllAdjacentString(str1) << endl;

  return 0;
}