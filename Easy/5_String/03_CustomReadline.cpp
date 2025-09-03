#include <bits/stdc++.h>

using namespace std;

void readLine(char *arr, int N, char delimitor) {
  int count = 0;
  char c;

  c = cin.get();  // get all character, including whitespace
  while (c != '\0') {
    // if reaching delimitor or count > N, break the loop
    if (count == N - 1 || c == delimitor) {
      break;
    }

    // add c into the array
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