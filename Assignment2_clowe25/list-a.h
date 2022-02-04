//Created by Christopher Lowe
//This is the header file for ECGR 3180 A2-part a
#include <iostream>
#include <string>

using namespace std;

class Node {  //used to initialize each individual object
  public:
  string id;
  Node *next;

  Node (string id, Node *next=nullptr) {
    this->id = id;
    this->next = next;
  }
};

class List {  //used to store functions and the linked list itself
  public:
  Node *head;
  List() {
    head = nullptr;
  }
  Node *first() {
    return head;
  }
  friend istream &operator>> (istream& sin, List &lst);
  friend ostream &operator<< (ostream& sout, List &lst);
  void prepend(string first);
  void append(string last);
};
