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

void swap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

/*

[0,0] --> [0,2]
[0,2] --> [2,2]
[2,2] --> [2,0]
[2,0] --> [0,0]


*/

vector<vector<int>> rotateTheMatrix(vector<vector<int>> &matrix) {
  if (matrix.size() == 0) return matrix;

  // Transpose
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = i; j < matrix[0].size(); j++) {
      if (i == j) continue;
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Reverse
  for (int i = 0; i < matrix.size(); i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }

  return matrix;
}

int main() {
  ios_base::sync_with_stdio(0);

  vector<vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

  rotateTheMatrix(matrix);

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}