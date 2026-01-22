#include <bits/stdc++.h>

using namespace std;

/*
        Convert Decimal to Binary
        - Get the remainder, and multiple with 10
        - Continue to do it
*/
unsigned long long int decToBi(unsigned long long int n) {
  unsigned long long int result = 0, p = 1;

  // if number is binary, then get a digit buy % 2, not % 10

  while (n > 0) {
    int remainder = n % 2;
    result += remainder * p;  // _ _ _ _ 0, _ _ _ 0 1
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
    result += digit * p;
    p *= 2;
    n /= 10;
  }

  return result;
}

/*

        Convert string binay to decimal
*/

unsigned long long int biStringToDec(const string& n) {
  unsigned long long int result = 0, p = 1;

  // get the right most bit, convert

  // for (int i = n.size() - 1; i >= 0; i--) {
  // int bit = n[i] - '0';
  // result = result + bit * p;
  // p *= 2;
  // }

  if (n.length() == 0) return 0;

  for (int i = n.size() - 1; i >= 0; i--) {
    // get the last bit, but it's in the char, convert to int by - '0'
    int bit = n[i] - '0';
    result += p * bit;
    p *= 2;
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);

  cout << decToBi(10) << endl;
  cout << biToDec(101) << endl;
  cout << biStringToDec("1011") << endl;

  return 0;
}