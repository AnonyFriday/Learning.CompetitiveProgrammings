#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  // first loop
  // second loop start from the end of first loop

  int N;
  if (!(cin >> N) || N <= 0) {
    cout << "Invalid!";
  }

  char letter;

  // no. rows
  for (int i = 1; i <= N; i++) {
    // left loop
    letter = 'A';

    for (int a = 1; a <= i; a++) {
      cout << letter;
      letter++;
    }

    // Reset to the previous letter
    letter--;

    // right loop
    for (int a = 1; a <= i; a++) {
      cout << letter;
      letter--;
    }

    cout << endl;
  }

  return 0;
}