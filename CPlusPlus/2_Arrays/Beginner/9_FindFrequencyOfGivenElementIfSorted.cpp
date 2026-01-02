#include <bits/stdc++.h>

#include <unordered_map>

using namespace std;

/*

        1,2,2,2,2,3,4,5
        zal
*/

unordered_map<int, int> buildFrequencyTable(int *arr, int n) {
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++) {
    const int el = arr[i];
    freq[el]++;
  }

  return freq;
}

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

/*

        Main function

*/

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
  sort(arr, arr + N);

  printArrayCorrect(arr, N);

  // Using unordered_map (hashing table) to find the freq of element
  unordered_map<int, int> freqArr = buildFrequencyTable(arr, N);

  cout << "Element: " << k << ": " << freqArr[k];

  return 0;
}