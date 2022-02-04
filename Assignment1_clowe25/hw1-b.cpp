//Created by Christopher Lowe
//Problem 1B
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int prevInThree = 0;
    int prevInTwo = 0;
    int prevIn = 0;
    int input;
    int sum;
    int count = 0;
    
    sum = 0;
    cin >> input;
    while(!cin.eof()) {
        sum += input;
        prevInThree = prevInTwo;
        prevInTwo = prevIn;
        prevIn = input;
        cin >> input;
        count += 1;
    }
    cout << "Sum: " << sum << "  # of integers entered: " << count << endl;
    cout << "Final three inputs:\n" << prevInThree << "\n" << prevInTwo << "\n" << prevIn << endl;
    return 0;
}
