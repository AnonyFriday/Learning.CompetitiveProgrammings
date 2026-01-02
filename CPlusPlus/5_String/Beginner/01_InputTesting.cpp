#include <bits/stdc++.h>

#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  /*
        - cin: Read input up to the first whitespace (space, tag, newline)
        - cin.get(): Get a single character, which can be whitespace
        - cin.get(arr, n): Reads a string (including spaces) until \n is found
        - getline(cin, line): read the entire line easily
  */

  // // Cin
  // string name;
  // cin >> name;           // if input = "John Doe"
  // cout << name << endl;  // output = "John"  (stops at space)
  //
  // // cin.get()
  // char ch;
  // cin.get(ch);
  // cout << ch << endl;
  //
  // // cin.get(charArray, size)
  // char line[50];
  // cin.get(line, 50);
  // cout << line << endl;
  //

  // Using strstr, strcpy, strcat
  char name1[]{"Pratatek"};
  char company[] = "Coding Minute";
  char intern_name[] = {'x', 'y', 'z', '\0'};

  char greeting[100];
  cin.getline(greeting, 100, '.');
  cout << greeting << endl;

  char* foundIdx = strstr(company, greeting);
  if (foundIdx != NULL) {
    strcpy(greeting, "FOUNDED");
  } else {
    strcat(greeting, "NOT FOUNDED");
  }

  cout << greeting;

  return 0;
}