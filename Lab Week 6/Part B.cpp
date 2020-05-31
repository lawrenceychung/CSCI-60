#include <string>
#include <iostream>
using namespace std;

class Automobile
{
public:
    Automobile();
    Automobile(string imake, string imodel, int iyear, double iprice, int istall);
    bool park(bool lot[], int size);
    string make(){return make_;}
    string model(){return model_;}
    int year(){return year_;}
    double price(){return price_;}
    int stall(){return stall_;}
    void set_stall(int s){stall_ = s;}
private:
    string make_;
    string model_;
    int year_;
    double price_;
    int stall_;
};

Automobile::Automobile(){
    make_ = "";
    model_ = "";
    year_ = 0;
    price_ = 0;
    stall_ = -1;
}

Automobile::Automobile(string imake, string imodel, int iyear, double iprice, int istall){
    make_ = imake;
    model_ = imodel;
    year_ = iyear;
    price_ = iprice;
    stall_ = istall;
}

bool Automobile::park(bool lot[], int size){
    int spot = size;
    for(int i=0; i<size; i++){
        if(!lot[i])
            spot = i;
    }
    if(spot>=size)
       return false;
    else{
        lot[spot] = true;
        stall_ = spot;
        return true;
    }
}

class Pickup : public Automobile
{
public:
    Pickup();
    Pickup (string imake, string imodel, int iyear, double iprice, int istall, int ihauling_capacity, bool iextended_cab);

    int get_hauling_capacity() {return hauling_capacity;}
    bool get_extended_cab() {return extended_cab;}
    bool park(bool lot[], int size);

private:
    int hauling_capacity;
    bool extended_cab;
};

Pickup::Pickup(): Automobile()
{
    hauling_capacity = 0;
    extended_cab = false;
}

Pickup::Pickup (string imake, string imodel, int iyear, double iprice, int istall, int ihauling_capacity, bool iextended_cab): Automobile(imake, imodel, iyear, iprice, istall)
{
    hauling_capacity = ihauling_capacity;
    extended_cab = iextended_cab;
}

bool Pickup::park(bool lot[], int size)
{
    int spot = size;
    for (int i = 0; i < size; i++)
    {
        if (!lot[i] && !lot[i + 1])
        {
            spot  = i;
        }
    }
    if (spot > size)
    {
        return false;
    }
    else
    {
        set_stall(spot);
        lot[spot] = true;
        lot[spot + 1] = true;
        return true;
    }
}

class Van : public Automobile
{
public:
    Van();
    Van (string imake, string imodel, int iyear, double iprice, int istall, int inum_seats);

    int get_seats() {return num_seats;}
    bool park(bool lot[], int size);

private:
    int num_seats;
};

Van::Van(): Automobile()
{
    num_seats = 0;
}

Van::Van(string imake, string imodel, int iyear, double iprice, int istall, int inum_seats): Automobile(imake, imodel, iyear, iprice, istall)
{
    num_seats = inum_seats;
}

bool Van::park(bool lot[], int size)
{
    if (num_seats <= 7)
    {
        return Automobile::park(lot, size);
    }
    else
    {
        int spot = size;
        for (int i = 0; i < size; i++)
        {
            if (!lot[i] && !lot[i + 1])
            {
                spot  = i;
            }
        }
        if (spot > size)
        {
            return false;
        }
        else
        {
            set_stall(spot);
            lot[spot] = true;
            lot[spot + 1] = true;
            return true;
        }
    }
}

int main()
{
    Automobile A("Mercedes", "E320", 2001, 3000, 1);

    bool parking_lot [] = {0,1,0,0,1,0};
    cout << A.park(parking_lot, 6) << endl;
    cout << A.stall() <<endl;

    Pickup B;
    bool parking_lot_2 [] = {0,0,1,0,0,0};
    Pickup C ("Ford", "F-150", 2008, 8000, 2, 10000, 1);
    cout << B.stall() << endl;
    cout << B.park(parking_lot_2, 6) << endl;

    Van D;
    Van F ("Honda", "Oddessy", 2011, 5000, 3, 8);
    cout << F.stall() << endl;
    cout << F.park(parking_lot, 6) <<endl;

    return 0;
}
