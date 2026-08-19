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

char largestFrequencyCharacter(char *c, int size) {
  if (size == 0) return '\0';
  if (size == 1) return *c;

  int freq[256] = {0};

  // convert all to the freq table
  for (int i = 0; c[i] != '\0'; i++) {
    int charInInt = (int)c[i];
    freq[charInInt]++;
  }

  // find max
  int maxFreq = 0;
  char result = '\0';

  for (int i = 0; i < 256; i++) {
    if (freq[i] > maxFreq) {
      maxFreq = freq[i];
      result = (char)i;
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;
  cin.ignore();

  char str[N];
  cin.getline(str, N, '\n');

  cout << largestFrequencyCharacter(str, N) << endl;

  return 0;
}