#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int py = 39;
  int chem = 77;
  int math = 65;

  // int / int = int
  float avgInt = (py + chem + math) / 3;

  // int / float = float
  float avgFloat = (py + chem + math) / 3.0;

  cout << "Average Marks int" << avgInt;
  cout << "Average Marks float" << avgFloat;

  return 0;
}