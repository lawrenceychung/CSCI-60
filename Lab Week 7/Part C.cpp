
#include <iostream>
using namespace std;

template <typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        {
            if (a[i] <= high && a[i] >= low)
            {
                count++;
            }
        }
    return count;
}

int main()
{
    int count;
    int arr[] = {6,2,3,2,6,2};
    count = count_range(arr,6,2,4);

    cout << count << endl;
    return 0;
}
