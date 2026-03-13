#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  // Demo Vector
  vector<int> arr = {1, 2, 3, 4, 5, 6};

  // Fill Constructor
  // - fill all 10 slots with value 7
  vector<int> arr1(10, 7);

  // Vector are value type by default
  // - Changing arr2, won't affect arr 1
  vector<int> arr2 = arr1;
  arr2[0] = 1222;

  // Using pointer to affect the original array
  vector<int> *arr3 = &arr1;
  (*arr3)[0] = 1222;

  // - fill all 100 slots with value 0
  vector<int> visited(100, 0);

  // Methods
  arr.pop_back();
  arr.push_back(16);

  for (int i = 0; i < arr1.size(); i++) {
    cout << arr1[i] << endl;
  }

  return 0;
}