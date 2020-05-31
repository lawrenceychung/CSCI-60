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


size_t list_index(node *head_ptr, int target)
{
    int count;
    for (const node *p = head_ptr; p != nullptr; p = p->link())
    {
      if (p->data() == target)
      {
        return count;
      }
      count++;
    }
    return 99999999;
}

node *list_at(node *head_ptr, size_t n)
{
    node* temp = head_ptr;
    int count = 0;
    while (temp != nullptr)
    {
        if (count == n)
        {
            return temp;
        }
        count++;
        temp = temp->link();
    }
    return nullptr;
}

int main()

{
  node *head = new node(4, nullptr);
  node *tail(head);
  node *temp;


  temp = new node(1, nullptr);
  tail->set_link(temp);
  tail = temp;


  head = new node(1, head);
  head = new node(3, head);


  temp = new node(5, nullptr);
  tail->set_link(temp);
  tail = temp;


  for (const node *p = head; p != nullptr; p = p->link())
  {
    cout << p->data() << " ";
  }

  cout << endl;
  return 0;
}

//4.
// It's because the "node*temp = list_at(head, i);" is in the for loop. This means that it's reassigning the temp to
// list_at(head,i) every single time you run the for loop. This means that the function "list_at(head, i)" will run
// from the beginning every single time which is silly.

//5.
// It would be more efficient for a program that infrequently modifies its data but often accesses its data
// to use an array because it is easy to read through with a for/while loop. While a program that frequently modifies
// its data should use a linked list because you can simply change one pointer to add/subtract a number, instead of
// shifting multiple values such as in an array.
