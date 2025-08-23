#include <bits/stdc++.h>

using namespace std;

void maxElementsFrom2DArray(vector<vector<int>> &matrix) {
  for (auto &row : matrix) {
    // skip empty row
    if (row.empty()) continue;

    vector<int>::iterator it = row.begin();
    vector<int>::iterator maxEl = it;  // maxEl and it points to the same array element

    for (; it != row.end(); it++) {
      if (*it > *maxEl) {
        maxEl = it;
      }
    }

    cout << *maxEl << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  vector<vector<int>> v1 = {
      {1, -3, 2},
      {10, -3, 20},
      {5, -3, 8},
  };

  maxElementsFrom2DArray(v1);

  return 0;
}