//Created by Christopher Lowe
#include "list-b.h"

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

bool List::isEmpty() {  //checks if the list is empty
  if (head==NULL) {
    return 1;
  }
  return 0;
}

void List::reverse() {
  if (isEmpty()==1) {   //If list is empty, there is nothing to reverse
  }
  else {
    Node *temp, *prev, *curr;
    temp = NULL;
    prev = NULL;
    curr = head;
    while(curr != NULL) {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    head = prev;
  }
}

bool List::has_id(string find) {  //looks for a node with string find as id
  if (isEmpty()==1) {   //returns 0 if list is empty
    return 0;
  }
  Node *temp;
  temp = head;
  while(temp->next != NULL) {   //iterates through list
    if (temp->id == find) {
      return 1;
    }
    temp = temp->next;
  }
  if (temp->next == NULL) {   //checks last node
    if (temp->id == find) {
      return 1;
    }
  }
  return 0;
}
