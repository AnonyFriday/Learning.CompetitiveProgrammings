#include <bits/stdc++.h>
#define MAX_LEN 1000

using namespace std;

void readLongestString(int N, char *longest) {
  char inputStr[MAX_LEN];
  longest[0] = '\0';

  for (int i = 0; i < N; i++) {
    // get next input
    cin.getline(inputStr, MAX_LEN, '\n');

    if (longest == nullptr || strlen(longest) < strlen(inputStr)) {
      strcpy(longest, inputStr);
    }
  }
}

// Read a integer N followed by N strings
// Print the largest String
int main() {
  ios_base::sync_with_stdio(0);

  int N;
  char largestPtr[MAX_LEN];

  cin >> N;
  cin.get();  // consumme "\n"

  readLongestString(N, largestPtr);
  cout << largestPtr << endl;

  return 0;
}