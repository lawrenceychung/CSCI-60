#include <iostream>
#include <string>
using namespace std;

void PrintNamesInOrder (string names[], int nNames);

int main()
{
    string names[] = {"Tim", "Jill", "June", "Tony", "Tina", "Bob"};
    int nNames = 6;

    PrintNamesInOrder (names, nNames);

    return 0;
}
void PrintNamesInOrder (string names[], int nNames)
{
    void PrintNamesStartingWith (string names[], int nNames, char letter);
    char letter[nNames];
    for (int i = 0; i < nNames; i++)
    {
        letter[i] = names[i][0];
    }
    for (int j = 0; j < nNames; j++)
    {
        for (int k = j + 1; k < nNames; k++)
            {
                if (letter[j] == letter[k])
                {
                    for (int m = k; m < nNames; m++)
                    {
                        letter[k] = letter[m + 1];
                    }
                }
                else if (letter[j] > letter[k])
                {
                    char temp = letter[j];
                    letter [j] = letter[k];
                    letter[k] = temp;
                }
            }
    }
    for (int l = 0; l < nNames; l++)
    {
        PrintNamesStartingWith (names, nNames, letter[l]);
    }
}

void PrintNamesStartingWith (string names[], int nNames, char letter)
{
    for (int i = 0; i < nNames; i++)
    {
        if (names[i][0] == letter)
        {
            cout<< names[i] << endl;;
        }
    }
}
