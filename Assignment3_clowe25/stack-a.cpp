//Created by Christopher Lowe
#include "stack-a.h"

istream &operator>> (istream& sin, List &lst) {
  //adds new objects to list
  Node *temp;
  string id;

  sin >> id;
  while(sin) {  //allows input of entire list until eof
    temp = new Node(id,lst.head);
    lst.head = temp;
    sin >> id;
  }
  return sin;
}

ostream &operator<< (ostream& sout, List &lst) {
  //prints entire list
  Node *temp;
  string printList;
  temp = lst.head;
  if (lst.isEmpty()==1) { //invokes isEmpty() to check for empty list
    printList = "[]";
    sout << printList;
    return sout;
  }
  printList = printList + "[";
  //below loop prints all nodes except the final one
  while ((temp != nullptr) && (temp->next != nullptr)){
    printList += (temp->id + ", ");
    temp = temp->next;
  }
  printList += temp->id; //prints final node
  printList = printList + "]";
  sout << printList;  //outputs the entire list
  return sout;
}

bool List::isEmpty() {  //checks if the list is empty
  if (head==NULL) {
    return 1;
  }
  return 0;
}

void Stack::push(string addTo) {    //adds element to top
  Node *newBegin;
  newBegin = new Node(addTo);
  newBegin->next = head;
  head = newBegin;
}

void Stack::pop() {   //removes element from top
  Node *temp;
  temp = head;
  if (head->next == NULL) {
    head = NULL;
  }
  else {
    head = temp->next;
  }
}

ostream &operator<< (ostream& sout, Stack &stk) {
  Node *temp;
  string printStack;
  temp = stk.head;
  if (stk.isEmpty()==1) {   //If empty stack
    printStack = printStack + "[top] -------\n";
    printStack = printStack + "[bot] TTTTTTT";
    sout << printStack;
    return sout;
  }
  printStack = printStack +  "[top] -------\n";
  while (temp->next != NULL) {   //adds each element before last into the same string
    printStack += ("\t  " + temp->id + "\n");
    temp = temp->next;
  }
  printStack += ("\t  " + temp->id + "\n");   //adds final element
  printStack += "[bot] TTTTTTT";
  printStack += "\n";
  sout << printStack;
  return sout;
}

//iterates through cin and chooses action depending on input
void Stack::read(Stack &stk) {
  Node *temp;
  string x, y;
  int tempInt1, tempInt2;

  temp = head;
  cin >> x;
  while(cin) {
    if (x == "add") {   //adds the top two strings together
      x = head->id;
      y = head->next->id;
      stk.pop();
      stk.pop();
      tempInt1 = stoi(x);
      tempInt2 = stoi(y);
      tempInt1 = tempInt1 + tempInt2;
      x = to_string(tempInt1);
      stk.push(x);
    }
    else if (x == "print") {  //prints the topmost string and removes it
      x = head->id;
      stk.pop();
      cout << x << endl;
    }
    else if (x == "dump") {   //prints entire stack
      cout << stk;
    }
    else {    //adds new element
      stk.push(x);
      y = x;
    }
    cin >> x;
  }
}
