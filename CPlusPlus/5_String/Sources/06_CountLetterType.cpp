#include <bits/stdc++.h>

#include <cctype>

using namespace std;

/*

        Count Letter Types
        The ending character is $

*/
int main() {
  ios_base::sync_with_stdio(0);

  int alphabets = 0;
  int digits = 0;
  int whitespaces = 0;
  int special = 0;

  int N;
  cin >> N;
  cin.ignore();

  char ptr[N];

  // when reaching $, being replaced by the \0
  cin.getline(ptr, N, '$');

  for (int i = 0; ptr[i] != '\0'; i++) {
    char ch = ptr[i];

    if (isdigit(ch)) {
      digits++;
    } else if (isalpha(ch)) {
      alphabets++;
    } else if (isspace(ch)) {
      whitespaces++;
    } else {
      special++;
    }
  }

  cout << "Alphabets: " << alphabets << "\n";
  cout << "Digits: " << digits << "\n";
  cout << "Whitespaces: " << whitespaces << "\n";
  cout << "Special: " << special << "\n";

  return 0;
}