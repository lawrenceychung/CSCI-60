#include <iostream>

using namespace std;


class ListNode {
private:
  int data;
  ListNode* next;
public:
  ListNode(int n) : data(n), next(nullptr) { };
  ListNode(int n, ListNode* p) : data(n), next(p) { };
  friend class List;
};

class List {
private:
  ListNode* head;
  ListNode* tail;
public:
  List() : head(nullptr), tail(nullptr) { };

  void InsertFront(int n) {
    head = new ListNode(n, head);
    if (tail == nullptr) tail = head;
  };

  void InsertBack(int n) {
    if (tail == nullptr) {
      head = tail = new ListNode(n);
    } else {
      tail->next = new ListNode(n);
      tail = tail->next;
    }
  };

  void Print() {
    cout << "List: ";
    for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
      cout << ptr->data << " ";
    }
    cout << endl;
  };

  // Note that Append is fast if you have tail.
  // Note also that Append will share nodes between the two lists.
  // This may lead to problems when one list calls InsertBack.
  void Append(const List& L2) {
    tail->next = L2.head;
    tail = L2.tail;
  };

};


int main() {
  List L1;
  L1.InsertBack(8);
  L1.InsertBack(3);
  L1.InsertBack(1);
  List L2;
  L2.InsertBack(1);
  L2.InsertBack(6);

  // Line A

  L1.Append(L2);
  L2.InsertFront(2);
  L1.InsertBack(4);
  L2.InsertBack(9);
  L1.InsertBack(5);

  // Line B
  
  return 0;
}



  
