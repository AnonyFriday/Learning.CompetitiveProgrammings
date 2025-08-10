#include <bits/stdc++.h>

#include <iomanip>

using namespace std;

/*
        Find avg of 5 integers and print the output upto 4 decimal places
*/
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);

  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  int sum = a + b + c + d + e;
  std::cout << fixed << setprecision(4) << (float)sum / 5 << endl;

  return 0;
}