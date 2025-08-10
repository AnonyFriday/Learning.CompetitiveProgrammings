#include <bits/stdc++.h>

#define RAD 5

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  // datatype list
  int x;

  cout << "Size of int:          " << sizeof(x) << " bytes" << endl;
  cout << "Size of int:          " << sizeof(int) << " bytes" << endl;
  cout << "Size of short:        " << sizeof(short) << " bytes" << endl;
  cout << "Size of long:         " << sizeof(long) << " bytes" << endl;
  cout << "Size of long long:    " << sizeof(long long) << " bytes" << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;

  cout << "Size of float:        " << sizeof(float) << " bytes" << endl;
  cout << "Size of double:       " << sizeof(double) << " bytes" << endl;
  cout << "Size of long double:  " << sizeof(long double) << " bytes" << endl;

  cout << "Size of char:         " << sizeof(char) << " byte" << endl;
  cout << "Size of bool:         " << sizeof(bool) << " byte" << endl;

  cout << "Size of pointer (int*): " << sizeof(int*) << " bytes" << endl;
  cout << "Size of pointer (double*): " << sizeof(double*) << " bytes" << endl;

  std::cout << "sizeof(char)    = " << sizeof(char) << "\n";
  std::cout << "sizeof(char8_t) = " << sizeof(char8_t) << "\n";
  std::cout << "sizeof(char16_t)= " << sizeof(char16_t) << "\n";
  std::cout << "sizeof(char32_t)= " << sizeof(char32_t) << "\n";
  std::cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << "\n";

  // datatype modifiers
  int a = -1;
  unsigned int b = 4294967295;
  long long int c = 4294967295;

  // compile-time fixed-size sequence of N bits
  cout << "Signed -1 in bits:     " << bitset<64>(a) << endl;
  cout << "Unsigned 4294967295:   " << bitset<64>(b) << endl;
  cout << "Signed 4294967295 in bits: " << bitset<64>(c) << endl;

  // char
  char ac = 'A';
  std::cout << "Char A: " << ac << endl;
  std::cout << "Char A in Int: " << (int)ac << endl;

  char32_t emoji = U'😊';
  std::cout << "Code point U+"
            << std::hex << std::uppercase
            << static_cast<unsigned>(emoji) << endl;

  // const
  std::cout << "RAD * RAD =" << RAD * RAD << endl;

  const float pi = 3.14;
  std::cout << "pi * RAD =" << pi * RAD << endl;

  // type casting (implicit casting)
  int at = 14;
  bool ab = 1;
  char acc = 'A';
  float af = 10.5;

  std::cout
      << std::dec
      << at + ab << endl;

  std::cout
      << std::dec
      << af + ab << endl;

  std::cout
      << std::dec
      << acc + ab << endl;

  std::cout
      << acc << endl;

  // type-casting (explicit casting)
  // - using c++ style
  int acasting = static_cast<int>(3.14);

  int aInCCasting = (int)3.14;

  std::cout << "Casting in C++: " << acasting << endl;

  std::cout << "Casting in C: " << aInCCasting << endl;

  return 0;
}
