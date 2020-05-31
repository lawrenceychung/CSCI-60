#include <iostream>
#include <string>

using namespace std;

class Student {
public:
  Student() { name = "unknown"; };
  Student(string n) { name = n; };
  void Print() { cout << name << endl; };
  string GetName() { return name; };
private:
  string name;
};

class Course {
public:
  // (a) [2 points] Given course id as input, initialize member variable id. Also initialize nstudents and capacity to zero.
  Course(int i) {
      id = i;
      nstudents = 0;
      capacity = 0;
  };
  // (b) [5 points] Add student to the class. Update nstudents accordingly. If capacity of member variable students is not enough to contain the new student,
  //allocate more space. New_capacity should be (2 * (old_capacity + 1)). Capacity is the length of the students array. For example, if 5 students have been added,
  //then nstudents is 5, capacity is 6, and the length of students array is 6. However, students[5] is just a dummy object that does not represent any real Student in the Course. Make sure your program has no memory leak.
  void AddStudent(Student s) {
      if (nstudents == capacity)
      {
          Student *temp = students;
          int new_capacity = 2 * (capacity + 1);
          students = new Student[new_capacity];
          for (int i = 0; i < capacity; i++)
          {
             students[i] = temp[i];
          }
          delete [] temp;
          capacity = new_capacity;
      }

      students[nstudents] = s.GetName();
      nstudents ++;

  };
  // (c) [6 points] Remove all students with the input name from the Course. If nstudents becomes less than 1/4 of capacity, then free memory such that new capacity is 1/2 of old capacity. Make sure your program has no memory leak.
  void DeleteStudentsWithName(string name) {
      for (int i = 0; i < nstudents; i++)
      {
          if (students[i].GetName() == name)
          {
              for (int k = i; k < nstudents; k++)
              {
                  students[k] = students[k + 1];
              }
              nstudents--;
          }
      }

      if ((nstudents / capacity) < 0.25)
      {
          Student *temp = students;
          students = new Student[capacity / 2];

          for (int i = 0; i < nstudents; i++)
          {
              students[i] = temp[i];
          }
          delete [] temp;

          capacity = capacity / 2;
      }

  };
  // (d) [2 points] Print the names of all the actual Student objects in the Course. Do not print dummy objects. Also print nstudents and capacity after printing names.
  void PrintStudents() {
      for (int i = 0; i < nstudents; i++)
      {
          students[i].Print();
      }

      cout << "Number of Students : " << nstudents << endl;
      cout << "Capacity : " << capacity << endl;
  };
private:
  int capacity;
  int nstudents;
  Student* students;
  int id;
};


int main()
{
    Course c1(15472);
    c1.AddStudent(Student("Ann"));
    c1.AddStudent(Student("Bob"));
    c1.AddStudent(Student("Crystal"));
    c1.AddStudent(Student("Diane"));
    c1.AddStudent(Student("Edward"));
    c1.AddStudent(Student("Frank"));
    c1.AddStudent(Student("George"));
    c1.AddStudent(Student("Frank"));
    c1.AddStudent(Student("Diane"));
    c1.AddStudent(Student("Diane"));
    c1.AddStudent(Student("Henry"));

    c1.PrintStudents();

    // c1.DeleteStudentsWithName("Diane");
    cout << "deleted Diane" << endl;

    c1.PrintStudents();

    c1.DeleteStudentsWithName("Frank");
    cout << "deleted Frank" << endl;

    c1.PrintStudents();


    c1.AddStudent(Student("Henry"));
    c1.DeleteStudentsWithName("Ann");
    c1.DeleteStudentsWithName("Bob");
    c1.DeleteStudentsWithName("Crystal");
    c1.DeleteStudentsWithName("Edward");
    c1.DeleteStudentsWithName("Irene");

    cout << "Deleted whole bunch." << endl;

    c1.PrintStudents();

    c1.DeleteStudentsWithName("Henry");
    cout << "Deleted Henry" << endl;

    c1.PrintStudents();

    return 0;
}

/*
Sample output:
Ann
Bob
Crystal
Diane
Edward
Frank
George
Frank
Diane
Diane
Henry
nstudents: 11
capacity: 14
deleted Diane
Ann
Bob
Crystal
Edward
Frank
George
Frank
Henry
nstudents: 8
capacity: 14
deleted Frank
Ann
Bob
Crystal
Edward
George
Henry
nstudents: 6
capacity: 14
Deleted whole bunch.
George
Henry
Henry
nstudents: 3
capacity: 14
Deleted Henry
George
nstudents: 1
capacity: 7

*/
