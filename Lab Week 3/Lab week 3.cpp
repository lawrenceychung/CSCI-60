#include <iostream>
using namespace std;

class ModInt
{
public:
    ModInt(int skip, int song)
    {
        num = song;
        mod = skip;
    }

    ModInt()
    {
        num = 0;
        mod = 1;
    }

    int getMod()
    {
      return mod;
    }
    int getNum()
    {
      return num;
    }

    void operator +=(ModInt rhs);

private:
    int num;
    int mod;
};

bool operator ==(ModInt lhs, ModInt rhs)
{
    if (lhs.getMod() == rhs.getMod() && lhs.getNum() == rhs.getNum())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ModInt::operator +=(ModInt rhs)
{
  if(mod == rhs.mod)
  {
     num = (num + rhs.num) % mod;
  }
  else
  {
      num = -1;
      mod = -1;
  }
}

ModInt operator +(ModInt lhs, ModInt rhs)
{
    if (lhs.getMod() == rhs.getMod())
    {
        int temp = (lhs.getNum() + rhs.getNum()) % lhs.getMod();

        return ModInt(lhs.getMod(), temp);
    }
    else
    {
        return ModInt(-1,-1);
    }
}

int main()
{
    ModInt A(100,103);
    ModInt B(100,107);

    bool answer = A == B;
    cout<< answer << endl;

    cout<< (A + B).getNum() << endl;

    return 0;
}
