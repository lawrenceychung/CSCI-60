#include <iostream>
using namespace std;

template <typename T1, typename T2>
int count_exact (T1 a[], T2 size, T1 find)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == find)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int int_arr[] = {6, 2, 3, 2, 6, 2};
    int int_test = count_exact(int_arr, 6, 2);
    cout << int_test << endl;

    string find = "abc";
    string string_arr[] = {"abc", "def", "ghi", "abc", "ghi", "abc"};
    int string_test = count_exact(string_arr, 6, find);
    cout << string_test << endl;

    return 0;
}
