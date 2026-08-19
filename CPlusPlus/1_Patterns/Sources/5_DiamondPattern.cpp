#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  if (!(cin >> N) || N % 2 == 0) {
    cout << "Please enter a positive odd number\n";
    return 0;
  }

  int iMid = (N / 2) + 1;

  // upper part
  for (int i = 1; i <= iMid - 1; i++) {
    int stars = i * 2 - 1;
    int spaces = iMid - i;

    for (int s = 1; s <= spaces; s++) {
      cout << " ";
    }

    for (int sa = 1; sa <= stars; sa++) {
      cout << "*";
    }
    cout << endl;
  }

  // mid
  for (int i = 1; i <= N; i++) {
    cout << "*";
  }
  cout << endl;

  // lower part
  for (int i = iMid - 1; i >= 1; i--) {
    int stars = i * 2 - 1;
    int spaces = iMid - i;  // since mid = 4, max space is 3

    for (int s = 1; s <= spaces; s++) {
      cout << " ";
    }

    for (int sa = 1; sa <= stars; sa++) {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}