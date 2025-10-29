#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int* arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << "index: " << i << ", value: " << arr[i] << endl;
  }
}

/*

        Due to missing one number, than we can use math to calculate the sum of AP from 1 to n, and

*/
int findMissingNumber(int* arr, int size, int d = 1) {
  if (size == 1) return arr[0];

  // since size (n-1), then sum from 1 - n = 1 - (size + 1)
  long long int n = (long long)size + 1;
  long long int expectedSum = 1LL * n * (n + 1) / 2;

  // Calculate the actual sum of arr
  long long int actualSum = 0;
  for (int i = 0; i < size; i++) {
    actualSum += arr[i];
  }

  return (int)(expectedSum - actualSum);
}

/*

        By using the concept of XOR
        A = 1 XOR 3 XOR 4
        Expected = 1 XOR 2 XOR 3 XOR 4

        Missing = A XOR B = 2, due to cancel out attribute
*/

int findMissingNumberXOR(int* arr, int size, int d = 1) {
  if (size == 1) return arr[0];

  long long int missing = 0;

  for (int i = 0; i < size; i++) {
    missing ^= arr[i];
  }

  for (int i = 1; i <= size + 1; i++) {
    missing ^= i;
  }

  return (int)missing;
}

int main() {
  ios_base::sync_with_stdio(0);

  srand(time(nullptr));

  int arr[4] = {1, 3, 4, 5};

  printArrayCorrect(arr, 4);
  cout << "Missing: " << findMissingNumber(arr, 4) << endl;
  cout << "Missing: " << findMissingNumberXOR(arr, 4);

  return 0;
}