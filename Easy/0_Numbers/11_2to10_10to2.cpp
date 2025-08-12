#include <bits/stdc++.h>

using namespace std;

/*
        Convert Decimal to Binary
        - Get the remainder, and multiple with 10
        - Continue to do it
*/
unsigned long long int decToBi(unsigned long long int n) {
  unsigned long long int result = 0, p = 1;

  while (n > 0) {
    int remainder = n % 2;
    result = result + remainder * p;
    p *= 10;
    n /= 2;
  }

  return result;
}

/*
        Convert Binary to Decimal
*/
unsigned long long int biToDec(unsigned long long int n) {
  unsigned long long int result = 0, p = 1;

  while (n > 0) {
    int digit = n % 10;
    result = result + digit * p;
    p *= 2;
    n /= 10;
  }

  return result;
}

/*

        Convert string binay to decimal

*/

unsigned long long int biStringToDec(string n) {
  unsigned long long int result = 0, p = 1;

  for (int i = n.size() - 1; i >= 0; i--) {
    int bit = n[i] - '0';
    result = result + bit * p;
    p *= 2;
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);

  cout << decToBi(10) << endl;
  cout << biToDec(1000111) << endl;
  cout << biStringToDec("1000111") << endl;

  return 0;
}