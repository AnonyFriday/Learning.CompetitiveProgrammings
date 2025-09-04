#include <bits/stdc++.h>

using namespace std;

void readLine(char *arr, int N, char delimitor) {
  // get each character
  // add to the array
  // loop until reaching \0 or reaching the delimitor
  int count = 0;
  char c;

  c = cin.get();  // get all chracter, including whitespace

  while (c != '\0') {
    if (c == delimitor || count == N - 1) {
      break;
    }

    arr[count++] = c;
    c = cin.get();
  }

  arr[count] = '\0';
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;

  if (cin >> N) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  char arr[N];

  readLine(arr, N, '\n');
  cout << arr << endl;
  cout << strlen(arr) << endl;

  return 0;
}