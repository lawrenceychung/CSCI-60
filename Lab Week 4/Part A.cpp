
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint()
    {
        for (size_t i = 0; i < CAPACITY; i++)
        {
            data_[i] = 0;
        }
    };

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const string & number)
    {
        size_t k = number.length();
        for (size_t i = 0; i < number.length(); i++)
        {
            int temp =  number[k-1] - '0';
            data_[i] = temp;
            k--;
        }
        for (size_t j = number.length(); j < CAPACITY; j++)
        {
            data_[j] = 0;
        }
    };

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](size_t pos) const
    {
        if (pos >= CAPACITY)
        {
            return 0;
        }
        else
        {

            return data_[pos];
        }
    };

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b)
    {
        for (size_t i = 0; i < CAPACITY; i++)
        {
            int total = data_[i] + b[i];
            if (total > 9)
            {
                data_[i] = total - 10;
                data_[i + 1] += 1;
            }
            else
            {
                data_[i] = total;
            }
        }
    };
    void operator -= (const biguint & b);

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);
ostream& operator <<(ostream& out, const biguint& b)
{
    for (size_t i = biguint::CAPACITY - 1; i > 0; i--)
    {
        out << b[i];
    }
    out << b[0];
    return out;
};

int main()
{
    string number = "1472";
    biguint a(number);
    biguint b(number);

    int k = 3;
    cout<< "Digit in position " << k << " : " << a[k] << endl;
    cout<< "Number: " << a << endl;
    a += b;
    cout << "Added Numbers: " << a << endl;;


    return 0;
}
