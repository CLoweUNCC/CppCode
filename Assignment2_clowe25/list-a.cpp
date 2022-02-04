//Created by Christopher Lowe
//This program contains the definitions for all of the member functions of class List
#include "list-a.h"

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
  cout << "[";
  //below loop prints all nodes except the final one
  while ((temp != nullptr) && (temp->next != nullptr)){
    printList += (temp->id + ", ");
    temp = temp->next;
  }
  printList += temp->id; //prints final node
  sout << printList;  //outputs the entire list
  cout << "]" << endl;
  return sout;
}

void List::prepend(string first) {
  //adds a new string to the beginning of the list
  Node *newBegin;
  newBegin = new Node(first);
  newBegin->next = head;
  head = newBegin;
}

void List::append(string last) {
  //adds a new string to the end of the list
  Node *newEnd, *temp;
  newEnd = new Node(last);
  temp = head;
  while (temp->next != NULL) { //iterates through each object until reaching the final object
    temp = temp->next;
  }
  temp->next = newEnd;  //assigns the final object of the list as newEnd
}
