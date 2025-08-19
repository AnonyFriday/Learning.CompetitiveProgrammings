#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int* arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

/*
        Using the technique of 2 pointers + sort
        - Big 0:
*/
bool threeSum(int* arr, int n, int target) {
  if (n < 3) return false;

  // sort the array
  sort(arr, arr + n);

  // Using 2 pointers technique to check with n
  // T = i + l + r --> T - i = l + r = T'
  // T' > target, l--
  // T' < target, r++
  // T' == target, return that triplet

  for (int i = 0; i < n - 2; i++) {
    int l = i + 1;
    int r = n - 1;

    while (l < r) {
      // convert int to long long int
      long long int sum = 1LL * arr[l] + arr[r] + arr[i];

      if (sum == target) {
        std::cout << "(" << i << ","
                  << l << ","
                  << r << ")";

        std::cout << "(" << arr[i] << ","
                  << arr[l] << ","
                  << arr[r] << ")";

        return true;
      }

      if (sum > target) {
        r--;
      } else if (sum < target) {
        l++;
      }
    }
  }

  // if not found, return false
  // or store that value in the array or something
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);

  int nums[] = {-2, 1, 5, -1, -4, 3};
  int n = sizeof(nums) / sizeof(nums[0]);

  int target;
  cin >> target;

  printArrayCorrect(nums, n);

  std::cout << (threeSum(nums, n, target) ? 1 : 0) << "\n";  // 1

  return 0;
}