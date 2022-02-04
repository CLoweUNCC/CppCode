//Created by Christopher Lowe
//Problem 1C
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  string input = "";
  string previousString = "";
  int max = 0;
  int count = 0;

  cin >> input;
  while (!cin.eof()) {
    count = count + 1;
    if (input == previousString || previousString == "") {
      if (count > max) {
        max = count;
      }
      else {

      }
    }
    else {
      count = 1;
    }
    previousString = input;
    cin >> input;
  }

  cout << "Max is " << max << endl;

  return 0;
}
