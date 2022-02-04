//Created by Christopher Lowe
//This program creates a queue and accepts input strings in the form of 'time' 'enter/exit', where time is a double. The program then calculates the average wait time for all individuals 'in line'
#include "queue-b.h"

int main() {
  Queue a_queue;
  int count = 0;
  string tmpStr1, tmpStr2;
  double tmpDb, avgWait, divideBy;
  avgWait = 0.0;
  divideBy = 0.0;

  cin >> tmpStr1;
  while(cin) {
    ++count;
    if (count%2 == 1) {
      tmpStr2 = tmpStr1;
    }
    else {
      if (tmpStr1 == "enter") {
        a_queue.enqueue(tmpStr2);
      }
      else if (tmpStr1 == "exit") {
        if (a_queue.isEmpty()==1) {
          cout << "Non existant customer exited the line" << endl;
          return 1;
        }
        a_queue.reverse();
        tmpStr1 = a_queue.getHead();
        a_queue.dequeue(a_queue);
        tmpDb = stod(tmpStr2) - stod(tmpStr1);
        avgWait += tmpDb;
        ++divideBy;
      }
      else {
        cout << "Syntax error around '" << tmpStr1 << "'" << endl;
        return 1;
      }
    }
    cin >> tmpStr1;
  }
  if (divideBy == 0.0) {
    cout << "No customers exited, so there is no wait times to average" << endl;
    return 0;
  }
  avgWait = avgWait / divideBy;
  cout << "Avg time spent in line is: " << avgWait << " minutes" << endl;
  if (a_queue.isEmpty()==0) {
    cout << "However, some people are still in line" << endl;
  }
  return 0;
}
