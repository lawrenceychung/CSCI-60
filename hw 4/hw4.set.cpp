#include <iostream>

using namespace std;

// A Set contains ints with no duplicates.
// Do not change or add new member functions or member variables except the
// ones asked for in the questions. Do not use std::set or std::unordered_set.
class Set {
public:
  Set() : data(nullptr), size(), capacity(0) {};

  // (c) [5 points] Write a constructor that takes two arguments:
  // int arr[], which is an array of ints to put into data, and
  // int len, which is the length of arr.
  // Post-conditions:
  // data[] should contain all the ints in arr[], except no duplicates. For
  // example, if 7 appears three times in arr[], it should only appear once
  // in data[].
  // size should be the number of ints data[] contains.
  // Initially, data should be null pointer, and capacity 0.
  Set(int arr[], int len)
  {
      size = 0;
      capacity = 0;
      for (int i = 0; i < len; i++)
      {
          Insert(arr[i]);
      }
  };

  // (b) [3 points] Modify the Insert function to make sure that
  // we don't insert a value that already exists in the set.
  void Insert(int val) {
    if (Exists(val) == false)
    {
        if (capacity < size + 1) {
          DoubleCapacity();
        }
        data[size] = val;
        size++;
    }
  };

  void DoubleCapacity() {
    int* old = data;
    data = new int[(capacity + 1 ) * 2];
    for (int i = 0; i < size; i++) {
      data[i] = old[i];
    }
    if (capacity > 0) delete [] old;
    capacity = (capacity + 1) * 2;
  };

  // (d) [2 points] Return that value at the given index.
  int GetVal(int ind)
  {
      return data[ind];
  };

  void Print() {
    for (int i = 0; i < size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  };

  // (e) [3 points] Swap the values of data[i] and data[j].
  void Swap(int i, int j)
  {
      int temp = data[i];
      data[i] = data[j];
      data[j] = temp;
  };

  int GetSize() {
    return size;
  };

  // (f) [4 points] Write the copy constructor. It is required that the data[]
  // for this object points to a different memory location as the data[] in
  // the copied object. Also, it is required to avoid memory leak.
  Set(const Set &s)
  {
      size = 0;
      capacity = 0;
      for (int i = 0; i < s.size; i++)
      {
          Insert(s.data[i]);
      }
  }
  // (g) [4 points] Overload the assignment operator. Sane requirements as
  // copy constructor.
  Set& operator = (const Set &s)
  {
      Set temp(s);
      return temp;
  }
  // (h) [2 points] Write the destructor. You must free memory so that there
  // is no memory leak.
  ~Set()
  {
      delete[] data;
  }


private:
  // (a) [2 points] Returns true if val is in data[], false otherwise.
  bool Exists(int val)
  {
      bool test = false;
      for (int i = 0; i < size; i++)
      {
          if (data[i] == val)
          {
              test = true;
              break;
          }
      }
      return test;
  };

  int* data;
  int capacity;
  int size;
};

// OrderedSet is like a Set: It cannot contain duplicate values.
// One additional property of OrderedSet: Its values are stored in order,
// from lowest value to highest value.
class OrderedSet : public Set {
public:
  OrderedSet() : Set() {};

  // (i) [5 points] Override the base Insert() function, so that the OrderedSet
  // remains in order, from smallest to biggest. First, put the new value at
  // the end of the array. Then, repeatedly swap backwards until it finds its
  // rightful position.

  void Insert(int val)
  {
      Set::Insert(val);

      for (int i = GetSize() - 1; i > 0; i--)
      {
          if (GetVal(i) < GetVal(i - 1))
          {
              Swap(i,(i - 1));
          }
      }
  }
};

int main() {
  int arr[6] = { 1, 4, 7, 7, 2, 15 };
  Set s(arr, 6);
  Set s2(s);
  s2.Swap(2,3);
  s.Print();
  s2.Print();

  s.Insert(5);
  s.Insert(1);
  s.Insert(9);
  s.Insert(4);
  s.Insert(5);
  s.Print();

  OrderedSet o;
  o.Insert(5);
  o.Insert(1);
  o.Insert(9);
  o.Insert(4);
  o.Insert(5);
  o.Insert(2);
  o.Insert(8);
  o.Insert(9);
  o.Insert(3);

  o.Print();

  return 0;
}

/*
Sample output (Note: This doesn't test all functionality):
1 4 7 2 15
1 4 2 7 15
1 4 7 2 15 5 9
1 2 3 4 5 8 9
*/
