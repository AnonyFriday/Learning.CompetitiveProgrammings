#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  // Demo Vector
  vector<int> arr = {1, 2, 3, 4, 5, 6};

  // Fill Constructor
  vector<int> arr1(10, 7);

  vector<int> visited(100, 0);

  // Methods
  arr.pop_back();
  arr.push_back(16);

  for (int i = 0; i < visited.size(); i++) {
    cout << visited[i] << endl;
  }

  return 0;
}