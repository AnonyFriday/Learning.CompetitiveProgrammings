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

std::vector<int> findMostAppearances(const vector<int> &a) {
  // condition
  if (a.size() <= 0 || a.size() > 100) return {0};

  const int minNum = 2;
  const int maxNum = 100;

  int max_occ = 0;
  int sum = 0;

  // using unordered_map to track the occr
  std::unordered_map<int, int> m = {};

  // find max occ
  for (const int &num : a) {
    if (num < minNum || num > maxNum) continue;

    m[num]++;
    if (m[num] > max_occ) {
      max_occ = m[num];
    }
  }

  // find sum of most
  for (const pair<int, int> &pair : m) {
    if (max_occ == pair.second) {
      sum += pair.first;
    }
  }

  return {sum};
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // Example 1: [1, 2, 2, 3, 3, 3, 4] -> Max freq is 3 (number 3). Sum = 3.
  vector<int> list1 = {1, 1, 1, 1, 2, 2, 3, 3, 3, 4};
  vector<int> result1 = findMostAppearances(list1);
  cout << "Example 1 Result: " << result1[0] << endl;  // Output: 3

  // Example 2: [5, 5, 8, 8, 1, 9] -> Max freq is 2 (numbers 5 and 8). Sum = 5 + 8 = 13.
  vector<int> list2 = {5, 5, 8, 8, 1, 9};
  vector<int> result2 = findMostAppearances(list2);
  cout << "Example 2 Result: " << result2[0] << endl;  // Output: 13

  // Example 3: [100, 100, 99, 99] -> Max freq is 2 (numbers 100 and 99). Sum = 199.
  vector<int> list3 = {100, 100, 99, 99};
  vector<int> result3 = findMostAppearances(list3);
  cout << "Example 3 Result: " << result3[0] << endl;  // Output: 199

  return 0;
}