#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Student {
  string name;
  int id;
  float gpa;
};

bool compare(const Student& a, const Student& b)
{
    return a.gpa > b.gpa;
};

bool operator == (const Student& a, const Student& b)
{
    return (a.name == a.name && a.id == b.id && a.gpa == b.gpa);
};

ostream& operator<<(ostream& out, const Student& a)
{
    out << a.name << ", " << a.id << ", " << a.gpa << endl;
}

class IntSet {
public:
  Set() { data.clear(); };
  void Insert(int val) {
    if (Find(val)) return;
    data.push_back(val);
  };
  bool Find(int val) {
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == val) {
        return true;
      }
    }
    return false;
  };
  int GetSize() { return data.size(); };
  void Print() {
    for (int i = 0; i < data.size(); i++) {
      cout << data[i];
    }
    cout << endl;
  };
private:
  vector<int> data;
};


template <typename T>
class TemSet
{
public:
    TempSet() { data.clear(); };
    void Insert(T value)
    {
        if(Find(value)) return;
        data.push_back(value);
    };

    bool Find(T value)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == value)
            {
                return true;
            }

        }
        return false;
    };

    int GetSize()
    {
        return data.size();
    };

    void Print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    };

    void Sort()
    {
        sort(data.begin(), data.end(), compare);
    };
private:
    vector<T> data;
};

template <typename T>
class TemOrSet: public TemSet<T>
{
public:
    TemOrSet():TemSet<T>() { };
    void Insert (T value)
    {
        TemSet<T>::Insert(value);
        TemSet<T>::Sort();
    };

    int GetSize()
    {
        TemSet<T>::GetSize();
    };

    void Print()
    {
        TemSet<T>::Print();
    }

private:

};
int main() {

  TemSet<int> s1;
  s1.Insert(7);
  s1.Insert(5);
  s1.Insert(5);
  s1.Insert(1);
  s1.Insert(7);
  cout << "Set size is: " << s1.GetSize() << endl;
  if (s1.Find(7)) cout << "7 found" << endl;
  if (s1.Find(2)) cout << "2 found" << endl;


  TemOrSet<Student> s2;

  Student t1 = { "Ann", 17, 4.0 };
  Student t2 = { "Bob", 5, 2.6 };
  Student t3 = { "Chris", 26, 3.7 };
  Student t4 = { "David", 9871, 3.9 };
  s2.Insert(t1);
  s2.Insert(t1);
  s2.Insert(t2);
  s2.Insert(t2);
  s2.Insert(t1);
  s2.Insert(t3);
  cout << "Set size is: " << s2.GetSize() << endl;
  s2.Print();
  if (s2.Find(t3)) cout << "t3 found" << endl;
  if (s2.Find(t4)) cout << "t4 found" << endl;

  return 0;
}
