//Created by Christopher Lowe
#include "queue-b.h"

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

string Queue::getHead() {
  return head->id;
}

void Queue::enqueue(string addTo) {    //adds element to end of queue
  Node *newBegin;
  newBegin = new Node(addTo);
  newBegin->next = head;
  head = newBegin;
}

void Queue::dequeue(Queue &que) {   //removes element from end of reversed queue, then rectifies it
  Node *temp;
  temp = head;
  if (head->next == NULL) {
    head = NULL;
  }
  else {
    head = temp->next;
  }
  que.reverse();
}
