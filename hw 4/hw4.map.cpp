// You can only include the following libraries:
// iostream, unordered_map, fstream, algorithm, vector
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

// You may write helper comparator functions here.
bool compare(const pair<string,double> &i, const pair<string,double> &j)
{
    return (i.second > j.second);
}


// Do not add any member functions or variables.
class Restaurant {
private:
  unordered_map<string, double> sales;
public:
  Restaurant() { };

  // 1. (6 points)
  // Read the given text file. Each line in the input file
  // is a food name and amount of the sale (including $ sign).
  // Food name and amount are separated by space.
  // Example input file is hw5.input.txt.
  // Read the input file and keep one entry per food item in the member
  // variable sales. The key is the food name, and the value is to total
  // value of sales.
  ReadFile(string fname) {
      ifstream myfile;
      myfile.open("hw4.input.txt");

      if (myfile.fail())
      {
          cout << "file failed to open" << endl;
          exit(1);
      }

      string name, temp;
      double amount;
      int count = 0;
      int addon = 0;
      while(myfile >> name)
      {
          count++;
          if (count % 2 == 0)
          {
              for (int i = 0; i < name.length(); i++)
              {
                  name[i] = name[i + 1];
              }
              amount = stod(name);
              if (addon > 0)
              {
                  sales[temp] += amount;
                  addon--;
              }
              else
              {
                  sales.insert(pair<string, double>(temp, amount));
              }
          }
          else
          {
              temp = name;
              for (auto it:sales)
              {
                  if (temp == it.first)
                  {
                      addon++;
                  }
              }
          }
      }


      myfile.close();
  };

  // 2. (2 points)
  // Print the total sales by name of the food item, in alphabetical order.
  // First print "Total by name".
  // Then for each food item, print one line. The line contains the food name,
  // space, and then the total value of sales.
  // Hint: Transfer from sales to vector, and sort vector.
  PrintByName() {
      cout << "Total by name:" << endl;

      vector<pair<string, double>> vec;
      copy(sales.begin(),sales.end(),back_inserter(vec));
      sort(vec.begin(),vec.end());

      for (auto it:vec)
      {
          cout << it.first << " $" << it.second << endl;
      }

  };

  // 3. (2 points)
  // Print the total sales in order of total sales amount.
  // First print "Total by amount".
  // Then for each food item, print one line. The line contains the food name,
  // space, and then the total value of sales.
  PrintByAmount() {
      cout << "Total by amount:" << endl;

      vector<pair<string, double>> vec;
      copy(sales.begin(),sales.end(),back_inserter(vec));
      sort(vec.begin(),vec.end(), &compare);

      for (auto it:vec)
      {
          cout << it.first << " $" << it.second << endl;
      }
  };
};

// Do not change main() function.
int main() {
  Restaurant R;
  R.ReadFile("hw4.input.txt");
  R.PrintByName();
  cout << endl;
  R.PrintByAmount();
  return 0;
}

/*
Sample output:

Total by name:
Chips $70.45
Cookie $19.28
Fries $3.99
Hamburger $112.14
Hotdog $20.9
Pizza $309.48
Sandwich $54.82
Soup $105.15
Taco $62.09

Total by amount:
Pizza $309.48
Hamburger $112.14
Soup $105.15
Chips $70.45
Taco $62.09
Sandwich $54.82
Hotdog $20.9
Cookie $19.28
Fries $3.99
*/
