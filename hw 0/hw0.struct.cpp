#include <iostream>

using namespace std;

struct Student {
  int id;
  string name;
  float gpa;
};

// 1. (3 points)
// Inputs: (1) arr: an array of Student, (2) len: the length of the array.
// Find the Student with the highest gpa in the array,
// and print his/her name, for example like this "Top student is Diane."
void PrintTopStudent(Student arr[], int len) {
string max;
for (int i = 0; i < len; i++)
{
    for (int k = i + 1; k < len - 1; k++)
        if (arr[i].gpa > arr[k].gpa)
        {
            max = arr[i].name;
        }
}

cout<< "Top student is " << max << "." << endl;
}

// 2. (2 points)
// Inputs:
// (1) arr, an array of Student
// (2) id, an integer
// (3) name, a string
// (4) len, the length of the input array
// Go through the entire array, if there is a Student with id the
// same as the input id, change the Student's name to the input name.
void ChangeName(Student arr[], int id, string name, int len) {
for (int i = 0; i < len; i++)
{
    if (arr[i].id == id)
    {
        arr[i].name = name;
    }
}
}

// 3. (1 point)
// Inputs: (1) arr: an array of Student, (2) len: the length of the array.
// Print all the Students in the given array, in this format, for example:
// "Ann (ID: 500) has gpa: 3.68"
void PrintAll(Student arr[], int len) {
for (int i = 0; i < len; i++)
{
    cout<< arr[i].name << " (ID: " << arr[i].id << ") has gpa: " << arr[i].gpa <<endl;
}
}


// 3. (4 points)
// Inputs: (1) arr: an array of Student, (2) len: the length of the array.
// Find the average gpa of all the Students in arr.
// Then print the names of all the Students whose gpa is higher than average,
// separated by commas.
// For example, "Above average students: Ann, Bob"
void PrintAboveAverage(Student arr[], int len) {
int count, above_count;
double total, avg;
string above_avg = "";

count = 0;
above_count = 0;

for (int i = 0; i < len; i++)
{
    total += arr[i].gpa;
    count++;
}
avg = total / count;

for (int i = 0; i < count; i++)
{
    if (above_count == 0)
    {
        if (arr[i].gpa > avg)
        {
            above_avg += arr[i].name;
            above_count++;
        }
    }
    else
    {
        if (arr[i].gpa > avg)
        {
            above_avg += ", " + arr[i].name;

        }
    }
}

cout<< "Above Average Students: " << above_avg <<endl;
}

int main() {
  Student student_array[4];

  student_array[0] = { 500, "Ann", 3.96 };
  student_array[1] = { 600, "Bob", 2.86 };
  student_array[2].id = 1283;
  student_array[2].name = "Cory";
  student_array[2].gpa = 3.68;
  student_array[3] = { 19225, "Diane", 3.22 };


  ChangeName(student_array, 1283, "Corey", 4);
  PrintTopStudent(student_array, 4);
  PrintAll(student_array, 4);
  PrintAboveAverage(student_array, 4);

  return 0;
}

/*
Output:
Top student is Ann.
Ann (ID: 500) has gpa: 3.96
Bob (ID: 600) has gpa: 2.86
Corey (ID: 1283) has gpa: 3.68
Diane (ID: 19225) has gpa: 3.22
Above average students: Ann, Corey
*/
