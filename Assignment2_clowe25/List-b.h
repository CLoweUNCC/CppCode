//Created by Christopher Lowe
#include <iostream>
#include <cstdlib>
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
  bool isEmpty();
  void reverse();
  bool has_id(string find);
};
