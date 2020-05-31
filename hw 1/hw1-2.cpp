#include <iostream>
#include <string>
using namespace std;

struct Animal
{
    string name;
    string sex;
    int age;
    float price;
    string species;
};

Animal Cheapest (string type, Animal a[], int size);
bool SameSpecies (Animal a, Animal b);

int main()
{
    Animal shelter[5];
    shelter[0] = {"Snoopy", "Male", 3, 100, "Dog"};
    shelter[1] = {"Garfield", "Male", 6, 50, "Cat"};
    shelter[2] = {"Brian", "Male", 4, 200, "Dog"};
    shelter[3] = {"Misty", "Female", 3, 25, "Dog"};
    shelter[4] = {"Sherlock", "Female", 3, 100, "Cat"};


    Animal cheap;
    cheap = Cheapest ("Cat", shelter, 5);
    cout<< cheap.name << endl;

    return 0;

}

Animal Cheapest (string type, Animal a[], int size)
{
    int species;
    Animal cheap;
    for (int i = 0; i < size; i++)
    {
        if (a[i].species == type)
        {
            for (int k = i + 1; k < size; k++)
            {
                species = SameSpecies (a[i], a[k]);
                if (species == 1)
                {
                    if (a[i].price < a[k].price)
                    {
                        cheap = a[i];
                    }
                    else
                    {
                        cheap = a[k];
                    }
                }
            }
        }
    }
    return cheap;
}
bool SameSpecies (Animal a, Animal b)
{
    if (a.species == b.species)
    {
        return true;
    }
}
