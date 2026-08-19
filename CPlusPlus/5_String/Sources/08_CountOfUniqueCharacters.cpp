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

int countOfDifferentCharacters(char c[], int size) {
  if (size == 0) return 0;
  if (size == 1) return 1;

  int seen[256] = {0};

  int count = 0;

  for (int i = 0; i < size; i++) {
    int charInInt = (int)c[i];

    if (seen[charInInt] == 0) {
      seen[charInInt]++;
      count++;
    }
  }

  return count;
}

/*

Using unordered map, just liek the above solution

*/
int countOfDifferentCharacters1(char c[], int size) {
  unordered_map<char, int> freq;

  for (int i = 0; i < size; i++) {
    freq[c[i]]++;
  }

  return freq.size();
}

int main() {
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;
  cin.ignore();

  char test[N];
  cin.getline(test, N, '\n');

  cout << countOfDifferentCharacters(test, N);
  cout << countOfDifferentCharacters1(test, N);

  return 0;
}