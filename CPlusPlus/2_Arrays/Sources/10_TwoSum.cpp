#include <bits/stdc++.h>

using namespace std;

/*

        Return the first pair that sum up to the target
        - using the hash table
        - num[i] + num[j] == target, then return (i, j)
        - stores {key, index}
        - check if the complement of Sum is within the hash or not, if within then return the pair
                          - since it's the early seen value, then store the index into the hash table
                          - that's why we return the pair {values[comValue], i}
*/

pair<int, int> twoSumUsingHash(int* arr, int n, int target) {
  if (n == 0 || n == 1) return {-1, -1};

  unordered_map<int, int> values = {};

  for (int i = 0; i < n; i++) {
    int value = arr[i];
    int comValue = target - value;

    // If found the comp, return the pair of indices immediately
    if (values.find(comValue) != values.end()) {
      return {values[comValue], i};
    }

    // If not, then add value into values
    // as the early seen value
    values[value] = i;
  }

  return {-1, -1};
}

/*

Using the 2 for loop ( not a good practise )

*/

pair<int, int> twoSumNormal(int* arr, int n, int target) {
  if (n == 0 || n == 1) return {-1, -1};

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((*(arr + i) + *(arr + j)) == target) {
        return {i, j};
      }
    }
  }

  return {-1, -1};
}

void printArrayCorrect(int* arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  srand(time(nullptr));

  int N, k;

  cin >> N >> k;

  int arr[N];

  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 10 + 1;
  }

  printArrayCorrect(arr, N);

  // Using normal
  pair<int, int> ans1 = twoSumNormal(arr, N, k);
  cout << "(" << ans1.first << "," << ans1.second << ")" << endl;

  // Using hash
  pair<int, int> ans2 = twoSumUsingHash(arr, N, k);
  cout << "(" << ans2.first << "," << ans2.second << ")" << endl;

  return 0;
}