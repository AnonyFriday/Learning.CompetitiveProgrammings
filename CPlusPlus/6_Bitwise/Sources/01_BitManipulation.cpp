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

// get ith bit
// 1100 1011
//      i   I want to get bit at location i
// Notice that we create a mask upto that position
// if 1100 1011
//		0000 1000
// using &, if > 0, then we know that number > 0, then that i is 1
// else, number == 0, thnen that i is 0
int getIthBit(int n, int i) {
  int mask = (1 << i);
  return (n & mask) > 0 ? 1 : 0;
}

// set ith bit (force ith to become 1)
void setIthBit(int &n, int i) {
  int mask = (1 << i);
  n = (n | mask);
}

// clear ith bit
void clearIthBit(int &n, int i) {
  int mask = ~(1 << i);
  n = n & mask;
}

// update ith bit
// = clear + set
// if v is 1, just like setIthBit
// if v is 0, just like clearIthBit
void updateIthBit(int &n, int i, int v) {
  // clear the ith bit
  int mask = ~(1 << i);
  n = n & mask;

  // create the value mask
  int value_mask = v << i;
  n = n | value_mask;
}

void updateIthBit2(int &n, int i, int v) {
  if (v == 1) {
    setIthBit(n, i);
  } else {
    clearIthBit(n, i);
  }
}

// clear i bits to 0
// 0101 0111 -> 0101 0000
void clearLastIBits(int &n, int i) {
  // if clear, then use the &
  // we want a mask 1111 0000
  // which from i to left side is all 1s
  // from i to right side is all 0s
  // since this is clear, then using &

  // e.g. i is 3
  int mask = (1 << i);        // 0000 1000
  int rightOnes = mask - 1;   // 0000 0111
  int leftOnes = ~rightOnes;  // 1111 1000

  n = n & leftOnes;
}

void clearLastIBits1(int &n, int i) {
  int mask = (-1 << i);  // 1111 1111 -> 1110 0000, i = 5
  n = n & mask;
}

// clear bit in range i and j
void clearBitsInRange(int &n, int i, int j) {
  // mask 1110 0001
  // we can create a mask by split into 2 part
  // i = 1, j = 4
  // A = 1110 0000, i
  // B = 0000 0001, j

  int A = (-1 << (j + 1));  // same trick as clearLastIBits
  int B = (1 << i) - 1;     // 0011 -> 0001
  int mask = A | B;

  n = n & mask;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // --- Examples ---
  int n;
  cin >> n;

  int n3 = 155;  // Binary: 1001 1011
  int i3 = 2;
  int j3 = 4;

  cout << "Original n3 = " << n3 << " (Binary: 1001 1011)"
       << "\n";
  cout << "Clearing bits from i=" << i3 << " to j=" << j3 << "..."
       << "\n";

  clearBitsInRange(n3, i3, j3);

  cout << "Resulting n3 = " << n3 << " (Binary: 1000 0011)"
       << "\n\n";

  cout
      << "Original n = " << n << " (Binary: 0001 0101)"
      << "\n\n";

  // 1. getIthBit
  cout << "--- Testing getIthBit ---"
       << "\n";
  cout << "Bit at position 0 is: " << getIthBit(n, 0) << "\n";  // 1
  cout << "Bit at position 1 is: " << getIthBit(n, 1) << "\n";  // 0
  cout << "Bit at position 4 is: " << getIthBit(n, 4) << "\n";  // 1
  cout << "n is unchanged: " << n << "\n\n";

  // 2. setIthBit
  cout << "--- Testing setIthBit ---"
       << "\n";
  int n_set = n;
  cout << "Setting bit at position 3 (which is 0)..."
       << "\n";
  setIthBit(n_set, 3);  // 0001 0101 -> 0001 1101
  cout << "Resulting n_set = " << n_set << " (Binary: 0001 1101)"
       << "\n\n";

  // 3. clearIthBit
  cout << "--- Testing clearIthBit ---"
       << "\n";
  int n_clear = n;
  cout << "Clearing bit at position 4 (which is 1)..."
       << "\n";
  clearIthBit(n_clear, 4);  // 0001 0101 -> 0000 0101
  cout << "Resulting n_clear = " << n_clear << " (Binary: 0000 0101)"
       << "\n\n";

  // 4. updateIthBit
  cout << "--- Testing updateIthBit ---"
       << "\n";
  int n_update = n;
  cout << "Updating bit at position 2 (is 1) to 0..."
       << "\n";
  updateIthBit(n_update, 2, 0);  // 0001 0101 -> 0001 0001
  cout << "Resulting n_update = " << n_update << " (Binary: 0001 0001)"
       << "\n";

  n_update = n;  // Reset n_update
  cout << "Updating bit at position 1 (is 0) to 1..."
       << "\n";
  updateIthBit(n_update, 1, 1);  // 0001 0101 -> 0001 0111
  cout << "Resulting n_update = " << n_update << " (Binary: 0001 0111)"
       << "\n\n";

  int n1 = 87;  // Binary: 0101 0111
  int i = 3;    // We want to clear the last 3 bits

  cout << "--- Testing clearLastIBits ---"
       << "\n";
  cout << "Original n = " << n1 << " (Binary: 0101 0111)"
       << "\n";

  // Call the function
  clearLastIBits(n1, i);

  cout << "After clearing last " << i << " bits..."
       << "\n";
  cout << "Resulting n = " << n1 << " (Binary: 0101 0000)"
       << "\n";

  // Example from your comment: 0101 0111 -> 0101 0000
  int n2 = 87;  // 0101 0111
  int i2 = 4;   // Clear last 4 bits

  cout << "\n--- Your Example ---"
       << "\n";
  cout << "Original n2 = " << n2 << " (Binary: 0101 0111)"
       << "\n";

  clearLastIBits1(n2, i2);  // Mask will be 1111 0000

  cout << "After clearing last " << i2 << " bits..."
       << "\n";
  cout << "Resulting n2 = " << n2 << " (Binary: 0101 0000)"
       << "\n";  // n2 is 80

  return 0;
}