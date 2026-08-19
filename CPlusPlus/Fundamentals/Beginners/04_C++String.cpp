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

void printAString(const string &a) {
  std::cout << a << endl;
}

int main() {
  ios_base::sync_with_stdio(0);

  // String initialization
  string s1;
  string s2{"hello"};
  string s3{s2};
  string s4{"Hello World"};
  string s5{s2, 0, 2};
  string s6(3, 'X');

  printAString(s1);
  printAString(s2);
  printAString(s3);
  printAString(s4);
  printAString(s5);
  printAString(s6);

  // Print info before adding
  std::cout << "add: " << &s6 << endl;
  std::cout << "size: " << s6.size() << endl;
  std::cout << "capacity: " << s6.capacity() << endl;

  // Print info after adding
  s6.insert(0, "idont know hat is this but it's good and feel so right");
  std::cout
      << "add: " << &s6 << endl;
  std::cout << "size: " << s6.size() << endl;
  std::cout << "capacity: " << s6.capacity() << endl;

  // at(2)
  std::cout << s6.at(2) << endl;

  // input using getline(std::line, str)
  std::getline(std::cin, s1, '$');
  std::cout << s1 << endl;
  std::cout << s1.size() << endl;
  std::cout << "substr: " << s1.substr(1, 5) << endl;
  size_t x = s1.find("x");

  std::cout << std::string::npos << endl;
  if (x != std::string::npos) {
    std::cout << "find: " << x << endl;
  } else {
    std::cout << "not found: " << x << endl;
  }

  // string comparision
  string a = "Apple";
  string b = "Banana";
  string c = "Apple";

  // Equality
  if (a == c) {
    cout << a << " == " << c << endl;
  }

  // Inequality
  if (a != b) {
    cout << a << " != " << b << endl;
  }

  // Lexicographic comparison
  if (a < b) {
    cout << a << " < " << b << endl;  // "Apple" comes before "Banana"
  }

  if (b > a) {
    cout << b << " > " << a << endl;  // "Banana" comes after "Apple"
  }

  // string iterator
  string name1 = "coding is fun";
  for (int i = 0; i < name1.length(); i++) {
    cout << name1[i] << ",";
  }
  cout << endl;
  for (int i = 0; name1[i] != '\0'; i++) {
    cout << name1[i] << ",";
  }
  cout << endl;
  for (const char &x : name1) {
    cout << x << ",";
  }
  cout << endl;
  for (int x : name1) {
    cout << x << ',';
  }
}
