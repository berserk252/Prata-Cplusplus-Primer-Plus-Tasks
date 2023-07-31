#include<iostream>
#include<time.h>
#include<string>
#include<cmath>
#include<cctype>
#include<list>
#include<bitset>
#include<algorithm>
#define SIZE 10
using namespace std;

int main(void){

    list<string> con1, con2, con3;
    string str;



    cout << "Met please enter your list of friends(Enter \"end\" for continue):";

    while(getline(cin, str) && str != " " && str[0] != 0)
    {
        con1.push_back(str);
    }

    cout << "Net please enter your list of friends(Enter \"end\" for continue):";

    while(getline(cin, str) && str != " " && str[0] != 0)
    {
        con2.push_back(str);
    }

    con1.sort();
    con2.sort();
    con3.merge(con1);
    con3.merge(con2);
    con3.unique();

    cout << "This is the merge list\n";

    for(auto itr = con3.begin(); itr != con3.end(); itr++)
    {
        cout << *itr << endl;
    }




    return 0;
}
