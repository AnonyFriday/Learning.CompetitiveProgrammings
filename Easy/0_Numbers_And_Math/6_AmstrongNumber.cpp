#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int n, count = 0, sum = 0;
  cin >> n;

  int temp = n;

  // num of digits
  while (temp != 0) {
    count++;
    temp /= 10;
  }

  // sum
  temp = n;
  while (temp != 0) {
    int digit = temp % 10;
    sum += pow(digit, count);
    temp /= 10;
  }

  cout << (sum == n ? 1 : 0);

  return 0;
}