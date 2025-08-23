#include <bits/stdc++.h>

using namespace std;

void mergeTwoSortedVectors(vector<int> &v1, vector<int> &v2) {
  int n = v1.size();
  int m = v2.size();

  vector<int> result;

  if (n == 0 && m != 0) {
    result = v2;
    return;
  } else if (m == 0 && n != 0) {
    result = v1;
    return;
  }

  int i = 0, j = 0;

  while (i < n && j < m) {
    // compare [i] < [j]
    if (v1[i] <= v2[j]) {
      result.push_back(v1[i++]);
    } else {
      result.push_back(v2[j++]);
    }
  }

  // remaning
  while (i < n) {
    result.push_back(v1[i++]);
  }

  while (j < m) {
    result.push_back(v2[j++]);
  }

  // for (const int &x : result) {
  // cout << x << endl;
  // }
}

int main() {
  ios_base::sync_with_stdio(0);

  vector<int> v1 = {1, 5, 7, 10};
  vector<int> v2 = {-5, -3, -1, 11, 24};

  // using manual
  mergeTwoSortedVectors(v1, v2);

  // using merge
  vector<int> merged;
  std::merge(
      v1.begin(), v1.end(),
      v2.begin(), v2.end(),
      back_inserter(merged));

  for (const int &x : merged) {
    cout << x << endl;
  }

  return 0;
}