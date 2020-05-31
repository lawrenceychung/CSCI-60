#include <iostream>
#include <cstdlib>
using namespace std;

// 1.  Address     Name    value
//a.   2000         i       20
//     2001         j       1000
//     2002         k       1004
//     __________________________
//     1000         x       20
//     1004         y       30

//b.   2000         i       23
//     2001         j       1000
//     2002         k       1004
//     __________________________
//     1000         x       28
//     1004         y       15

//c.   __________________________
//     1000         x       28
//     1004         y       15


// 2.
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
    }

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

// 3.
class Account
{
public:
    Account ()
    {
        balance = 0.0;
    };
    Account(float b)
    {
        balance = b;
    };

    float get_balance() const
    {
        return balance;
    };
    void withdraw (float amount)
    {
        balance -= amount;
    };
    void print()
    {
        cout << "balance: $" << balance << endl;
    };
private:
    float balance;
};

class Atm
{
public:
    Atm ()
    {
        twenties = 0;
        tens = 0;
    };
    Atm (int num_of_twenties, int num_of_tens)
    {
        twenties = num_of_twenties;
        tens = num_of_tens;
    };

    int get_twenties()
    {
        return twenties;
    };
    int get_tens()
    {
        return tens;
    };

    void GetCash(int amount, Account& b)
    {
            if (b.get_balance() - amount <  0)
            {
                cout << "insufficient funds in your account." << endl;
            }
            else
            {
                if (amount % 10 == 0)
                {
                    int temp_twenties = amount / 20;
                    if (temp_twenties > twenties)
                    {
                        temp_twenties = twenties;
                    }
                    int temp_tens = (amount - temp_twenties * 20) / 10;
                    if (temp_tens > tens)
                    {
                        temp_tens = 0;
                        temp_twenties = 0;
                        cout << "insuffcient funds in ATM" << endl;
                    }
                    else
                    {
                        b.withdraw(amount);
                    }

                    b.print();
                    twenties -= temp_twenties;
                    tens -= temp_tens;
                    cout << "withdrawing " << temp_twenties << " twenty dollar bill(s) and " << temp_tens << " ten dollar bill(s)" << endl;
                }
                else
                {
                    cout << "invalid amount" << endl;
                }
            }
    };

    void operator += (Atm& rhs)
    {
        twenties += rhs.twenties;
        rhs.twenties = 0;
        tens += rhs.tens;
        rhs.tens = 0;
    };

    void restock (int new20s, int new10s)
    {
        twenties += new20s;
        tens += new10s;
    };

private:
    int twenties;
    int tens;
};

bool operator == (Atm lhs, Atm rhs)
{
    if (lhs.get_tens() == rhs.get_tens() && lhs.get_twenties() == rhs.get_twenties())
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator << (ostream& out, Atm a)
{
    out << "Number of 20 dollar bill(S) in ATM: " << a.get_twenties() << endl;
    out << "Number of 10 dollar bill(s) in ATM: " << a.get_tens() << endl;
}

int main()
{
    cout << "Outputs from Number 2" << endl;
    Rational A(12,36);
    Rational B(1,3);
    Rational C(2,34);

    Rational test_product;
    Rational test_sum;
    bool test_equality;

    test_product = B * C;
    cout << test_product.get_numerator() << "/" << test_product.get_denominator() << endl;
    test_sum = A + B;
    cout << test_sum.get_numerator() << "/" << test_sum.get_denominator() << endl;
    // test_equality = A == B;
    // cout << test_equality << endl;
    // test_equality = B == C;
    // cout << test_equality << endl;
    // A += B;
    // cout << A.get_numerator() << "/" << A.get_denominator() << endl;
    A.reduce();
    cout << A.get_numerator() << "/" << A.get_denominator() << endl;

    // cout << endl << "Outputs from Number 3" << endl;
    // Account D;
    // Account F(1000);
    // Atm H(100,100);
    // Atm I(1,2);
    // Atm J(100,100);
    //
    // bool test_equal = H == J;
    // cout << test_equal << endl;
    // test_equal = H == I;
    // cout << test_equal << endl;
    //
    // H += I;
    // cout << "ATM has " << H.get_twenties() << " and " << H.get_tens() <<endl;
    // I.restock (1,2);
    // cout << "ATM has " << I.get_twenties() << " and " << I.get_tens() <<endl;
    //
    // cout << "Case: drawing from an account with sufficient funds and an ATM with sufficient funds" << endl;
    // H.GetCash(230,F);
    // cout << "Case: drawing from an account with insufficient funds and an ATM with sufficient funds" << endl;
    // H.GetCash(560,D);
    // cout << "Case: drawing from an account with sufficient funds and an ATM with insufficient funds" << endl;
    // I.GetCash(510,F);
    // cout << "Case: drawing from an account with insufficient funds and an ATM with insufficient funds" << endl;
    // I.GetCash(110,D);
    //
    // cout << H;

    return 0;
}
