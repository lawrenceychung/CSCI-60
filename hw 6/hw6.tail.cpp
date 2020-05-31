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
      tail = head = new ListNode(n);
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

  // (a) [6 points]
  // Write non-recursive Remove.
  // If n exists in the list, unlink that node from the list.
  // The new list should be the same as the previous list except with
  // all nodes containing n removed.
  // Also free the memory associated with that node.
  // Make sure head and tail are set correctly.
  void Remove(int n) {
      ListNode* prev = head;

      for (ListNode* ptr = head; ptr != nullptr; ptr = prev->next)
      {
          if (n == ptr->data)
          {
              if (ptr == tail && ptr == head)
              {
                  delete ptr;
                  head = nullptr;
                  tail = nullptr;
                  return;
              }
              else if (ptr->next == nullptr)
              {
                  tail = prev;
                  prev->next = ptr->next;
                  delete ptr;
              }
              else if (ptr == head)
              {
                  ptr = ptr->next;
                  delete prev;
                  head = ptr;
                  prev = ptr;
              }
              else
              {
                  prev->next = ptr->next;
                  delete ptr;
              }
          }
          else
          {
               prev = ptr;
          }
      }
      if (n == head->data)
      {
         ListNode* test = head->next;
         delete head;
         head = test;
      }


  };

  // (b) [2 points]
  // Write Destructor. Free all the memory of all the nodes.
  ~List() {
      ListNode* ptr;
      ListNode* temp;
      for (ptr = head; ptr != nullptr; ptr = temp)
      {
          temp = ptr->next;
          delete ptr;
      }
  };

  // (c) [6 points]
  // Write Assignment Operator. First, free all the memory of all the nodes
  // of self. Then for each node in the other list, create a new node with
  // the same data. And join the nodes in the same way so that this list
  // is identical to the other list. Make sure the nodes of this list are
  // not linked to the nodes of the other list.
  List& operator=(const List& other) {
      ListNode* current = head;
      ListNode* next;
      while (current != nullptr)
      {
          next = current->next;
          delete current;
          current = next;
      }
      head = nullptr;
      tail = nullptr;


      ListNode* temp = other.head;
      while (temp != nullptr)
      {
          InsertBack(temp->data);
          temp = temp->next;
      }


      return *this;

  };

  // (d) [6 points]
  // Write RemoveNextK. Find the first instance of n on the list.
  // Then remove the next k items on the list. If n doesn't exist in the list,
  // do nothing. If there are less than k items on the list after n, then
  // n's next should just be set to null pointer.
  void RemoveNextK(int n, int k) {
      int count = 0;
      ListNode* temp;
      ListNode* start;
      for (ListNode* ptr = head; ptr != nullptr; ptr = temp)
      {
          if (ptr->next == nullptr)
          {
              start->next = nullptr;
              return;
          }
          if (count > 0 && count < k)
          {
              temp = ptr->next;
              delete ptr;
              count++;
          }
          else if (count == k)
          {
              start->next = ptr->next;
              delete ptr;
              return;
          }
          else
          {
              temp = ptr->next;
          }
          if (n == ptr->data)
          {
              start = ptr;
              count = 1;
              temp = ptr->next;
          }
      }

  };

};

int main() {
  List L;
  L.InsertBack(80);
  L.InsertBack(2);
  L.InsertFront(7);
  L.InsertFront(8);
  L.InsertBack(50);
  L.InsertFront(2);
  L.InsertFront(2);
  L.InsertBack(20);
  List L2;
  L2.InsertFront(1);
  L2.InsertBack(2);
  L2 = L; // Test assignment operator
  cout << "L2: "; L2.Print();
  L.Print();
  L.Remove(7);
  cout << "L2: "; L2.Print();
  L.Print();
  L.Remove(2);
  L.Print();
  L.Remove(20);
  L.Print();
  L.Remove(50);
  L.Print();
  L.Remove(5);
  L.InsertFront(12);
  L.InsertBack(17);
  L.Print();
  L.Remove(8);
  L.Print();
  L.Remove(80);
  L.Print();
  L.Remove(12);
  L.Remove(17);
  L.Print();
  L = L2;
  L2.InsertFront(512);
  L.Print();
  cout << "L2: "; L2.Print();
  L2.RemoveNextK(8, 2);
  cout << "L2: "; L2.Print();
  L2.RemoveNextK(50, 3);
  cout << "L2: "; L2.Print();

  return 0;
}

/*
Sample output:
L2: List: 2 2 8 7 80 2 50 20
List: 2 2 8 7 80 2 50 20
L2: List: 2 2 8 7 80 2 50 20
List: 2 2 8 80 2 50 20
List: 8 80 50 20
List: 8 80 50
List: 8 80
List: 12 8 80 17
List: 12 80 17
List: 12 17
List:
List: 2 2 8 7 80 2 50 20
L2: List: 512 2 2 8 7 80 2 50 20
L2: List: 512 2 2 8 2 50 20
L2: List: 512 2 2 8 2 50
*/
