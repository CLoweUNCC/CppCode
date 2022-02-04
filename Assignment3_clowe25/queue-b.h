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
  bool isEmpty();
  void reverse();
};

class Queue : public List {
  public:

  string getHead();
  void enqueue(string addTo);
  void dequeue(Queue &que);
};
