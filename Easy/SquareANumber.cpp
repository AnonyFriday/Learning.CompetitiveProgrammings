#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

#ifdef DEBUG
  cout << "[DEBUG] Debugging is enabled." << endl;
#else
  cout << "[INFO] Debugging is NOT enabled." << endl;
#endif

  double a;
  cin >> a;
  cout << "Square Root: " << sqrt(a);

  cout << "\nSquare: " << a * a;

  return 0;
}