#include <bits/stdc++.h>

// #include <algorithm>
// #include <cassert>
// #include <climits>
// #include <cmath>
// #include <cstring>
// #include <iostream>
// #include <list>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <unordered_map>
// #include <vector>
//
using namespace std;

const double E = 1e-8;
const double PI = acos(-1);

/*

Instead of looping the entire number and modulo it.
We check the last bit if it't 1, then add p * bit to result.
Then p *= 10 for binary location

*/
long long unsigned convertToBinary(int n) {
  if (n == 0 || n == 1) return n;

  int answer = 0;
  int p = 1;  // storing next position of the next bit
              // at the left most bit
  while (n > 0) {
    // if last bit > 0, then it's 1, else 0
    int lastBit = (n & 1) > 0;

    answer += lastBit * p;
    p *= 10;     // next bit location
    n = n >> 1;  // next last bit
  }

  return answer;
}

string convertToBinaryString(int n) {
  if (n == 0) return "0";
  if (n == 1) return "1";

  string answer = "";

  while (n > 0) {
    int lastBit = (n & 1) > 0;
    char lastBitChar = lastBit + '0';
    answer.push_back(lastBitChar);
    n = n >> 1;
  }

  std::reverse(answer.begin(), answer.end());

  return answer;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  cout << convertToBinary(-10) << endl;
  cout << convertToBinaryString(123) << endl;
  cout << convertToBinary(1) << endl;
  cout << convertToBinaryString(0) << endl;

  return 0;
}