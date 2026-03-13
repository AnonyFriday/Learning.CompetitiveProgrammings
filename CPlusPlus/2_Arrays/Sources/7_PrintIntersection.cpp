#include <bits/stdc++.h>

using namespace std;

void printArrayCorrect(int *arr, int n) {
  cout << "In Function 3: " << n << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

/*

- so looping the a first, and check inside b
- if match then check inside if that number is already or not
- if not, add, if dont, skip

*/

void intersect(int *a, int n, int *b, int m) {
  cout << "In Function 4" << endl;

  if (n == 0 || m == 0) return;

  int minBound = n > m ? m : n;
  int maxBound = n > m ? n : m;
  int c[minBound];
  int g = 0;

  for (int i = 0; i < minBound; i++) {
    // assumeming
    bool found = false;
    int el = a[i];

    // if found, then break, if not, continue but not evaluate the already
    // If found then move to next block
    // If not found, then continue next code
    for (int j = 0; j < maxBound; j++) {
      if (el == b[j]) {
        found = true;
        break;
      }
    }

    if (!found) continue;

    // check the result if already exist or not
    bool already = false;
    for (int z = 0; z < g; z++) {
      if (a[i] == c[z]) {
        already = true;
        break;
      }
    }

    if (!already) {
      c[g++] = a[i];
    }
  }

  // print from the array
  for (int i = 0; i < g; i++) {
    cout << c[i] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  srand(time(nullptr));

  int n,
      m;

  cin >> n >> m;

  int a[n],
      b[m];

  for (int i = 0; i < n; i++) {
    a[i] = rand() % 10 + 1;
  };

  for (int j = 0; j < m; j++) {
    b[j] = rand() % 10 + 1;
  }

  printArrayCorrect(a, n);
  printArrayCorrect(b, m);

  intersect(a, n, b, m);

  return 0;
}