#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

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



int main()
{
    string number = "1472";
    dbiguint a(number);
    dbiguint b(number);
    dbiguint c("12345");

    int k = 3;
    cout<< "Digit in position " << k << " : " << a[k] << endl;
    cout<< "Number: " << a << endl;
    a += b;
    cout << "Added Numbers: " << a << endl;

    bool test2 = b >= c;
    cout << test2<< endl;

    int test = a.compare(c);
    cout << test << endl;

    string test3 = a.toStdString();
    cout << test3 << endl;
    return 0;
}
