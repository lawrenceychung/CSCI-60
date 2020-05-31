#include <iostream>
using namespace std;

//1.
double water(int n)
{
    if (n == 0)
    {
        return 10;
    }
    else
    {
        double temp = water (n - 1);
        temp /= 2;
        temp += 1;
        return temp;
    }
}


//2a. You can tell if an array with two elements is sorted if the first element is less
// than the second element.

//2b. You can tell if an array is still sorted when you add the nth element by comparing
// the last element to all previous elements, and the last element is the largest.

//2c.
bool isSorted (int a[], int n)
{
    if (n == 1)
    {
        return true;
    }
    if (a[n-2] < a[n-1])
    {
        isSorted (a, n - 1);
    }
    else
    {
        return false;
    }

}


int main()
{
    cout << water(3) << endl;

    int a[] = {1,2,3,4};
    cout << isSorted (a, 4) << endl;

    return 0;
}
