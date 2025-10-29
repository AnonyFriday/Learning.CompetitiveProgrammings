#include <bits/stdc++.h>

using namespace std;

/*
        A Function to compare the matching of 2 string
*/

bool compareChecker(const char *password, const char *expected_password) {
  int idx = 0;

  if (strlen(password) != strlen(expected_password)) return false;
  if (strlen(password) == 0 || strlen(expected_password) == 0) return false;

  // check every el in the password
  while (password[idx] != '\0') {
    if (password[idx] != expected_password[idx]) return false;

    idx++;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;
  cin.ignore();

  const char *expected_password = "VUKIMDUY";
  char password[N];

  // consume the password, without '\n'
  cin.getline(password, N, '\n');

  // comparting
  if (compareChecker(password, expected_password)) {
    cout << "matched";
  } else {
    cout << "not matched";
  }

  return 0;
}