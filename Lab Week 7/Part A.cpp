#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

//Part A

//1.
//a.
// int main(){
//     set<string> a;
// }
//b.
// int main(){
//     map<string, int> b;
// }
//c.
// int main(){
//     vector<int, string> c;
// }

//2.
int main(){
    set<string> a;
    map<string, int> b;
    vector<string> c;

    ifstream myfile;
    myfile.open("lab4.txt");

    if (myfile.fail())
    {
        cout << "file failed to open" << endl;
        exit(1);
    }

    string line;
    while (getline(myfile, line))
    {
        int count = 0;
        a.insert(line);
        c.push_back(line);
        count++;
        b[line]++;
    }

    myfile.close();

    ofstream output("output_file.txt");
    ofstream output2("output_file_2.txt");
    ofstream output3("output_file_3.txt");

    for (auto it:a)
    {
        output << it << endl;
    }
    for (auto it:b)
    {
        output2 << it.second << " " <<  it.first << endl;
    }
    int count = 0;
    for (auto it:c)
    {
        output3 << count << " "<< it << endl;
        count++;
    }

//Part B
    cout << "Meals served: " << count << endl;
    cout << "Number of people who have visted: " << a.size() << endl;

    int sum = 0;
    int counting;
    for (auto it:b)
    {
        sum += it.second;
        counting++;
    }
    cout << "Average number of times someone received services: " << sum/counting << endl;

    return 0;
}
