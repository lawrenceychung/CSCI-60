#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

//1.
class Rational
{
public:
    Rational()
    {
        numerator = 1;
        denominator = 1;
    };

    Rational(int num, int denom)
    {
        numerator = num;
        denominator = denom;
    };

    int get_numerator()
    {
        return numerator;
    };

    int get_denominator()
    {
        return denominator;
    };

    void set_numerator(int n)
    {
        numerator = n;
    };

    void set_denominator(int n)
    {
        denominator = n;
    };

    void operator += (Rational rhs)
    {
        if (denominator != rhs.denominator)
        {
            numerator = ((numerator * rhs.denominator) + (rhs.numerator * denominator));
            denominator = (denominator * rhs.denominator);
        }
        else
        {
            numerator = (numerator + rhs.numerator);
            denominator = denominator;
        }
    };

    void reduce()
    {
        for (int i = numerator; i > 0; i--)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;
                break;
            }
        }
    };

private:
    int numerator;
    int denominator;
};

Rational operator * (Rational lhs, Rational rhs)
{
    Rational fraction_product;
    fraction_product.set_numerator(lhs.get_numerator() * rhs.get_numerator());
    fraction_product.set_denominator(lhs.get_denominator() * rhs.get_denominator());
    fraction_product.reduce();

    return fraction_product;
};

Rational operator + (Rational lhs, Rational rhs)
{
    Rational fraction_sum;

    if (lhs.get_denominator() != rhs.get_denominator())
    {
        fraction_sum.set_numerator((lhs.get_numerator() * rhs.get_denominator()) + (rhs.get_numerator() * lhs.get_denominator()));
        fraction_sum.set_denominator(lhs.get_denominator() * rhs.get_denominator());
    }
    else
    {
        fraction_sum.set_numerator(lhs.get_numerator() + rhs.get_numerator());
        fraction_sum.set_denominator(lhs.get_denominator());
    }

    fraction_sum.reduce();

    return fraction_sum;
};

bool operator == (Rational lhs, Rational rhs)
{
    if (lhs.get_numerator() % rhs.get_numerator() == 0 && lhs.get_denominator() % rhs.get_denominator() == 0)
    {
        return true;
    }
    else if (rhs.get_numerator() % lhs.get_numerator() == 0 && rhs.get_denominator() % lhs.get_denominator() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

//2.
class dbiguint
{
public:
    // pre: none
    // post: creates a dynamic bigint value 0
    dbiguint()
    {
      capacity_ = 1;
      data_ = new unsigned short[1];
      data_[0] = 0;
    };

    // pre: s[0], ..., s[s.size()-1] are digits
    // post: creates a dbiguint whose digits are given in s
    dbiguint(const string & s)
    {
        size_t k = s.length();
        capacity_ = k;
        data_ = new unsigned short[k];

        for (size_t i = 0; i < capacity_; i++)
        {
            int temp =  s[k - 1] - '0';
            data_[i] = temp;
            k--;
        }
    };

    // pre: none    //NEW
    // post: makes this dynamic bigint a copy of given dynamic bigint
    void operator =(const dbiguint & b);

    // pre: none    //NEW
    // post: returns the size of the memory block of this dbiguint
    size_t size() const
    {
        return capacity_;
    }

    // pre: none
    // post: returns the digit at given pos (0 if does not exist)
    //       pos 0 is the least significant (units) digit
    unsigned short operator [](size_t pos) const
    {
        if (pos >= capacity_)
        {
            return 0;
        }
        else
        {
            return data_[pos];
        }
    };
    // pre: none
    // post: returns 0 if this dbiguint equals given dbiguint
    //               1 if this dbiguint >      given dbiguint
    //              -1 otherwise

    int compare(const dbiguint & b) const
    {
        int temp = 0;
        if (capacity_ > b.capacity_)
        {
            return 1;
        }
        else if (capacity_ < b.capacity_)
        {
            return -1;
        }
        else
        {
            for (int i = capacity_ - 1; i >= 0; i--)
            {
                if (data_[i] > b.data_[i])
                {
                    temp = 1;
                    return 1;
                }
                else if (data_[i] < b.data_[i])
                {
                    temp = 1;
                    return -1;
                }
                else
                {
                    if (temp == 0)
                    {
                        return 0;
                    }
                }

            }
        }
    };

    // pre: none
    // post: returns a string containing the digits and sign of this dbiguint
    string toStdString() const
    {
        string temp = "";
        for (int i = capacity_ - 1; i >= 0; i--)
        {
            temp += to_string(data_[i]);
        }

        return temp;
    };

    // pre: none
    // post: adds/subtracts given dbiguint to this dbiguint
    void operator +=(const dbiguint & b)
    {
        for (size_t i = 0; i < capacity_; i++)
        {
            if (b.capacity_ > capacity_)
            {
              reserve(b.capacity_);
            }
            int total = data_[i] + b[i];
            if (total > 9)
            {
                data_[i] = total - 10;
                data_[i + 1] += 1;
            }
            else if (total > 9 && i == capacity_ - 1)
            {
                reserve(capacity_ + 1);
                data_[i] = total - 10;
                data_[i + 1] = 1;
            }
            else
            {
                data_[i] = total;
            }
        }
    };

    void operator -=(const dbiguint & b);
    void operator *=(const dbiguint & b);

    //pre: none
    //post: if newcapacity_ <= capacity_ then do nothing (cannot shrink)
    //      else allocate a new block with size newcapacity_
    //      copy existing digits and fill the rest with 0
    void reserve(size_t new_capacity)
    {
      if (new_capacity > capacity_)
      {
          unsigned short *temp = new unsigned short[new_capacity];

          for (size_t i = 0; i < capacity_; i++)
          {
              temp[i] = data_[i];
          }
          for (size_t j = capacity_; j < new_capacity; j++)
          {
              temp[j] = 0;
          }

          delete [] data_;

          data_ = temp;
          capacity_ = new_capacity;
      }
    };


private:
    unsigned short *data_;
    size_t capacity_;

    // INVARIANTS:
    //    data_ points to (has the address of) a dynamic array
    //    of capacity_ digits
    //    data_[0] = least significant (units) digits
    //    data_[k] = digit at position k (or 0 if not used)


};


// nonmember functions

dbiguint operator +(const dbiguint & a, const dbiguint & b);
dbiguint operator -(const dbiguint & a, const dbiguint & b);
dbiguint operator *(const dbiguint & a, const dbiguint & b);

bool operator < (const dbiguint & a, const dbiguint & b)
{
    if (a.compare(b) == -1)
    {
        return true,true;
    }
    else
    {
        return false,false;
    }
};
bool operator <= (const dbiguint & a, const dbiguint & b)
{
    if (a.compare(b) == -1 || a.compare(b) == 0)
    {
        return true,true;
    }
    else
    {
        return false,false;
    }
};
bool operator == (const dbiguint & a, const dbiguint & b)
{
    if (a.compare(b) == 0)
    {
        return true,true;
    }
    else
    {
        return false,false;
    }
};
bool operator != (const dbiguint & a, const dbiguint & b)
{
    if (a.compare(b) != 0)
    {
        return true,true;
    }
    else
    {
        return false,false;
    }
};
bool operator >= (const dbiguint & a, const dbiguint & b)
{
    if (a.compare(b) == 1 ||a.compare(b) == 0)
    {
        return true,true;
    }
    else
    {
        return false,false;
    }
};
bool operator > (const dbiguint & a, const dbiguint & b)
{
    if (a.compare(b) == 1)
    {
        return true,true;
    }
    else
    {
        return false,false;
    }
};;

//istream & operator >> (istream & out, dbiguint & b);
ostream& operator <<(ostream& out, const dbiguint& b)
{
    for (size_t i = b.size() - 1; i > 0; i--)
    {
        out << b[i];
    }
    out << b[0];
    return out;
};

//3.
void IncrBy(int *a, int b)
{
    *a += b;
}

int* Greater(int *a, int *b)
{
    if (*a > *b)
    {
        return a;
    }
    else if (*a < *b)
    {
        return b;
    }
}

//4.
int *CreateNewArray(int start, int len)
{
    int *array;
    array = new int[len];
    for (int i = 0; i < len; i++)
    {
        array[i] = start + i;
    }

    return array;

}

int main()
{

    cout << "Outputs from Number 1" << endl;
    Rational A(12,36);
    Rational B(1,3);
    Rational C(2,34);
    Rational D(12,36);

    Rational test_product;
    Rational test_sum;
    bool test_equality;

    test_product = B * C;
    cout << test_product.get_numerator() << "/" << test_product.get_denominator() << endl;
    test_sum = A + B;
    cout << test_sum.get_numerator() << "/" << test_sum.get_denominator() << endl;
    test_equality = A == B;
    cout << test_equality << endl;
    test_equality = B == C;
    cout << test_equality << endl;
    A += B;
    A.reduce();
    cout << A.get_numerator() << "/" << A.get_denominator() << endl;
    D.reduce();
    cout << D.get_numerator() << "/" << D.get_denominator() << endl;

    cout << "Outputs from Number 2" << endl;

    string number = "1472";
    dbiguint a(number);
    dbiguint b(number);
    dbiguint c("12345");

    int k = 3;
    cout<< "Digit in position " << k << " : " << a[k] << endl;
    cout<< "Number: " << a << endl;
    a += b;
    cout << "Added Numbers: " << a << endl;

    bool test_bool = b >= c;
    cout << "Inequality Test: " << test_bool << endl;

    int test_compare = a.compare(c);
    cout << "Compare Test: " << test_compare << endl;

    string test_string = a.toStdString();
    cout << "String Number: " << test_string << endl;

    cout << "Outputs from Number 3" << endl;
    int x = 15;
    IncrBy (&x, 2);
    cout << x << endl;

    x = 10;
    int y = 15;
    int *iptr = Greater(&x,&y);
    cout << *iptr << endl;
    y = 2;
    cout << *iptr << endl;

    cout << "Outputs from Number 4" << endl;
    int *m = CreateNewArray(7,4);
    for (int i = 0; i < 4; i++)
    {
        cout << m[i] << " ";
    }

    return 0;
}
