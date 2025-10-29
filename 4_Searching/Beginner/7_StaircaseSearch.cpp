#include <bits/stdc++.h>

using namespace std;

/*

        Each row in the 2D array is sorted
        Using the Staircase Searching

*/

pair<int, int> stairCaseSearch(int (*arr)[4], int n, int m, int target) {
  if (n <= 0 || m <= 0) return {-1, -1};

  int r = 0, c = m - 1;

  while (r < n && c >= 0) {
    auto el = arr[r][c];

    if (el == target) {
      return {r, c};
    } else if (el < target) {
      r += 1;
    } else {
      c -= 1;
    }
  }

  return {-1, -1};
}

int main() {
  ios_base::sync_with_stdio(0);

  int matrix1[4][4] = {
      {1, 2, 3, 4},
      {2, 3, 4, 5},
      {3, 4, 5, 6},
      {4, 5, 6, 7}};
  int target1 = 90;
  pair<int, int> coord1 = stairCaseSearch(&matrix1[0], 4, 4, target1);
  cout << coord1.first << "," << coord1.second << endl;

  int matrix2[4][4] = {
      {1, 4, 7, 11},
      {2, 5, 8, 12},
      {3, 6, 9, 16},
      {10, 13, 14, 17}};
  int target2 = 13;
  pair<int, int> coord2 = stairCaseSearch(&matrix2[0], 4, 4, target2);
  cout << coord2.first << "," << coord2.second << endl;

  return 0;
}