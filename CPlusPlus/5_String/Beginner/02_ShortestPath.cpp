#include <bits/stdc++.h>

using namespace std;

/*

The Problem:
- You start at the origin (0,0).
- You are given a sequence of directions: N (north, +y), S (south, –y), E (east, +x), W (west, –x).
- Example input: "NNNEEWS".
- After following those steps, you end up at some final coordinate (x,y).
- The task is: instead of retracing all those instructions, output the shortest path string that gets you directly from (0,0) to (x,y).

Problem
- Instead of going a long way, find a shortest path from 0,0 to that desination

Input Example
- NNNEEWS

Output Example
- 1,2 --> since end at the 1,2 location


*/

string findShortestPath(string &input) {
  int x = 0, y = 0;

  for (const char &c : input) {
    switch (c) {
      case 'N': {
        y++;
        break;
      }
      case 'E': {
        x++;
        break;
      }
      case 'S': {
        y--;
        break;
      }
      case 'W': {
        x--;
        break;
      }
    }
  }

  string path;
  if (x > 0) path.append(x, 'E');
  if (x < 0) path.append(-x, 'W');
  if (y < 0) path.append(-y, 'S');
  if (y > 0) path.append(y, 'N');

  return path;
}

int main() {
  // ios_base::sync_with_stdio(0);

  // char ch = cin.get();
  // while (ch != '\n') {
  // cout << ch << endl;
  // ch = cin.get();
  // }

  string input;
  getline(cin, input);
  cout << findShortestPath(input);

  return 0;
}