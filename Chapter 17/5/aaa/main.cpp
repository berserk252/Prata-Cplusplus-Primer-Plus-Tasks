#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cctype>
#include<list>
#include<bitset>
#include<algorithm>
#define SIZE 10
using namespace std;

int main(void){
    ifstream f1("mat.dat"), f2("pat.dat");
    ofstream f3("matnpat.dat");

    list<string> con1, con2, con3;
    char str[10];

    while(f1.getline(str, 10, '\n') && str != " " && str[0] != 0)
    {
        con1.push_back((string)str);
    }

    //cout << "Net please enter your list of friends(Enter \"end\" for continue):";

    while(f2.getline(str, 10, '\n') && str != " " && str[0] != 0)
    {
        con2.push_back((string)str);
    }

    con1.sort();

    cout << "This is Mat's friend list:\n";

    for(auto itr = con1.begin(); itr != con1.end(); itr++)
    {
        cout << *itr << endl;
    }

    con2.sort();

    cout << "This is Pat's friend list:\n";

    for(auto itr = con2.begin(); itr != con2.end(); itr++)
    {
        cout << *itr << endl;
    }
    con3.merge(con1);
    con3.merge(con2);
    con3.unique();

    cout << "This is the merge list\n";

    for(auto itr = con3.begin(); itr != con3.end(); itr++)
    {
        cout << *itr << endl;
    }

    for(auto itr = con3.begin(); itr != con3.end(); itr++)
    {
        f3 << *itr << '\n';
    }

    f1.close();
    f2.close();
    f3.close();

    return 0;
}
