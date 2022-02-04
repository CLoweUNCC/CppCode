//Created by Christopher Lowe
//Problem 1A
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int count = 0;
  int subTotal = 0;
  int grandTotal = 0;
  int prevAccount = 0;
  int num;

  cin >> num;
  while (!cin.eof()) {
    ++count;
    if (count%2==1) {
      if (num!=prevAccount) {
        if (count!=1) {
          cout << "Subtotal:\t\t" << subTotal << endl;
          grandTotal = grandTotal + subTotal;
        }
        cout << "\nAccount Number\t" << "Expense" << endl;
        prevAccount = num;
        subTotal = 0;
        cout << num;
      }
      else {
        cout << num;
      }
    }
    else {
      cout << "\t\t\t" << num << endl;
      subTotal = subTotal + num;
    }
    cin >> num;
  }
  cout << "Subtotal:\t\t" << subTotal << endl << endl;
  grandTotal = grandTotal + subTotal;
  cout << "Grand Total:\t" << grandTotal << endl;

  return 0;
}
