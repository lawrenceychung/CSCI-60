#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class node
{
public:


    // pre: none
    // post: creates a new node with given data and link values
    node(const int & initdata, node * initlink);

    // pre: none
    // post: creates a new node with defaults: data=0 and link=nullptr
    node();

    // pre: none
    // post: returns data value stored in this node
    int data() const;

    // pre: none
    // post: returns link value stored in this node
    node * link();

    // pre: none
    // post: returns CONSTANT link value stored in this node
    const node * link() const;

    // pre: none
    // post: sets the data field to given value
    void set_data(const int & newdata);

    // pre: none
    // post: sets the link field to given value
    void set_link(node * newlink);


private:
    int data_;
    node * link_;
    // invariants:
    //  data_ holds the data value stored in this node
    //  link_ holds the address of the next node
};



node::node(){
  data_ = 0;
  link_ = nullptr;
}
node::node(const int& initdata, node * initlink)
{
    data_ = initdata;
    link_ = initlink;
}

int node::data() const
{
    return data_;
}

node * node::link()
{
    return link_;
}

//returns constant node pointer
const node * node::link() const//This is a const function - I promise the function doesn't change anything - On a const node*, you can only call const functions
{
    return link_;
}

void node::set_data(const int & newdata)
{
    data_ = newdata;
}

void node::set_link(node * newlink)
{
    link_ = newlink;
}





















class lbiguint
{
public:
    // pre: none
    // post: creates a linked list bigint with default value
    //       (default = 0)
    lbiguint()
    {
        head = new node(0, nullptr);
        tail = head;
    };

    // pre:
    //      s[0], ..., s[s.size()-1] are digits
    // post: creates a lbiguint whose digits are given in s
    //lbiguint(const std::string & s);


    // pre: none
    // post: returns dynamically allocated memory to heap
    //~lbiguint();

    // pre: none
    // post: returns the number of nodes of this lbiguint
    // std::size_t size() const;

    // pre: none
    // post: makes this linked list biguint a copy of given linked list biguint
    //void operator =(const lbiguint &);

    // pre: none
    // post: returns the digit at given pos (0 if does not exist)
    //       pos 0 is the least significant (units) digit
    //int operator [](std::size_t pos) const;

    // pre: none
    // post: returns 0 if this lbiguint equals given lbiguint
    //               1 if this lbiguint >      given lbiguint
    //              -1 otherwise
    //int compare(const lbiguint &) const;


    // pre: none
    // post: adds/subtracts given lbiguint to this lbiguint
    //void operator +=(const lbiguint &);
    //void operator -=(const lbiguint &);
    //void operator *=(const lbiguint &);

private:
    node *head, * tail;

    // INVARIANTS:
    //    head points to the ones place node in the linked list

};


// nonmember functions

//bool operator < (const lbiguint &, const lbiguint &);
//bool operator <= (const lbiguint &, const lbiguint &);
//bool operator == (const lbiguint &, const lbiguint &);
//bool operator != (const lbiguint &, const lbiguint &);
//bool operator >= (const lbiguint &, const lbiguint &);
//bool operator > (const lbiguint &, const lbiguint &);

//lbiguint operator +(const lbiguint &, const lbiguint &);
//lbiguint operator -(const lbiguint &, const lbiguint &);
//lbiguint operator *(const lbiguint &, const lbiguint &);

//std::ostream & operator << (std::ostream &, const lbiguint &);



/*
 biguint::biguint(){

     for(std::size_t i = 0; i<CAPACITY; i++){

             _data[i] = 0;
     }
 }
 biguint::biguint (const std::string & s)
 {
     for (int i = 0; i < CAPACITY; ++i)
         _data[i] = 0;

     if (s.size() == 0)
         return;

     char c = s[0];
     int j(0);
     for (int i = s.size()-1; j < CAPACITY && i >= 0; --i)
     {
         assert(isdigit(s[i]));
         _data[j] = s[i] - '0';
         ++j;
     }
 }


 unsigned short biguint::operator [](std::size_t pos) const
 {
     assert(pos < CAPACITY);
     return _data[pos];
 }



 int biguint::compare(const biguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string biguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 std::ostream & operator << (std::ostream & os, const biguint & b)
 {

     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

 std::istream & operator >> (std::istream & is, biguint & b)
 {
     std::string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }
*/
