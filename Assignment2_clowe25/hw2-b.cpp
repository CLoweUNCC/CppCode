//Created by Christopher Lowe
//This program creates a linked list based on user input, and then reverses it. This program also can check for an empty list, and can also check if a specific node value exists
#include "list-b.h"

int main() {
  List a_list;
  cin >> a_list;
  cout << a_list << endl;
  a_list.reverse();
  cout << a_list << endl;
  return 0;
}
