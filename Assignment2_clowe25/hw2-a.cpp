//Created by Christopher Lowe
//This program creates a linked list based on user input, adds a new string to both the beginning and end, and then outputs the list
#include "list-a.h"

int main() {
  List a_list;
  cin >> a_list;
  a_list.prepend("HEAD");
  a_list.append("TAIL");
  cout << a_list << endl;
  return 0;
}
