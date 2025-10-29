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

int** create2DArray(int rows, int cols) {
  int** arr = new int*[rows];

  for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }

  int value = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = value;
    }
  }

  return arr;
}

int main() {
  // dont use scanf and printf, only cin and cout
  ios_base::sync_with_stdio(0);

  // no more automatically calling cout.flush()
  cin.tie(0);

  // Kích thước mảng chỉ được biết khi chương trình chạy
  int N = 100;

  // 1. Cấp phát động: arrayPtr trỏ đến 100 ô nhớ int trên Heap
  int* arrayPtr = new int[N];

  // 2. Sử dụng:
  for (int i = 0; i < N; ++i) {
    arrayPtr[i] = i * 2;
  }

  cout << arrayPtr[2];

  // 3. Giải phóng: BẮT BUỘC để tránh Memory Leak
  delete[] arrayPtr;
  // Đặt con trỏ về NULL để tránh "dangling pointer" (con trỏ vô chủ)

  // if not set nullptr, ptr will access random value at the heap memory
  // which is not good
  cout << arrayPtr[2];

  arrayPtr = nullptr;

  int** arr2d = create2DArray(5, 5);

  return 0;
}