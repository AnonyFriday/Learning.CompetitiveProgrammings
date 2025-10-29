#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);

  // agrc
  cout << "Count: " << argc << endl;

  // argv
  for (int i = 0; i < argc; i++) {
    cout << "argv[" << i << "] = " << argv[i] << endl;
  }

  return 0;
}