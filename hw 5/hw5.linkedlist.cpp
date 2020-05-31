#include <iostream>

using namespace std;

class List;

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
public:

  List() : head(nullptr) { };

  void InsertFront(int n) {
    head = new ListNode(n, head);
  };

  void Print() {
    for (ListNode* p = head; p != nullptr; p = p->next) {
      cout << p->data << " ";
    }
    cout << endl;
  };

  void InsertBack(int n) {
    ListNode* temp = new ListNode(n);
    if (head == nullptr) {
      head = temp;
    } else {
      ListNode* p = head;
      while (p->next != nullptr) {
        p = p->next;
      }
      p->next = temp;
    }
  };

  // Remove recursively.

  ListNode* RemoveHelper(int n, ListNode* p) {
    if (p == nullptr) {
      return nullptr;
    } else if (p->data == n) {
      ListNode* temp = p->next;
      delete p;
      return temp;
    } else {
      p->next = RemoveHelper(n, p->next);
      return p;
    }
  };

  void Remove(int n) {
    head = RemoveHelper(n, head);
  };

  // (a) [5 points] Write FindLargest recursively.
  // You may write a helper function. Return the largest item in the list.
  // Assume that list only contains positive numbers. If empty list, return 0.
  int FindLargest()
  {
      int temp = 0;
      for (ListNode* p = head; p != nullptr; p = p->next)
      {
          if (p->data > temp)
          {
              temp = p->data;
          }
      }
      return temp;
  };

  // (b) [5 points] Write Double recursively.
  // You may write a helper function.
  // Insert a node after every node that is double the value of the existing
  // node. Example: { 5, 2, 8 } becomes { 5, 10, 2, 4, 8, 16 }.
  void DoubleHelper (ListNode* p)
  {
      if (p == nullptr)
      {
          return;
      }
      else
      {
          int test = (2 * p->data);
          ListNode* temp_next = p->next;
          ListNode* temp = new ListNode(test, temp_next);
          p->next = temp;
          DoubleHelper(temp->next);
      }
  }
  void Double()
  {
     DoubleHelper(head);
  };
};


int main() {
  List L;
  cout << "Largest: " << L.FindLargest() << endl;
  L.InsertFront(7);
  cout << "Largest: " << L.FindLargest() << endl;
  L.InsertFront(8);
  cout << "Largest: " << L.FindLargest() << endl;
  L.InsertBack(30);
  L.InsertBack(38);
  L.InsertBack(23);
  cout << "Largest: " << L.FindLargest() << endl;
  L.InsertFront(2);
  L.InsertBack(20);
  cout << "Largest: " << L.FindLargest() << endl;
  L.Double();
  L.Print();
  L.Remove(20);
  L.Remove(2);
  L.Remove(30);
  L.Double();
  L.Print();
  cout << "Largest: " << L.FindLargest() << endl;


  return 0;
}

/*
Sample output:
Largest: 0
Largest: 7
Largest: 8
Largest: 38
Largest: 38
2 4 8 16 7 14 30 60 38 76 23 46 20 40
4 8 8 16 16 32 7 14 14 28 60 120 38 76 76 152 23 46 46 92 40 80
Largest: 152
*/
