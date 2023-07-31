#include<iostream>
#include<time.h>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<bitset>
#include<algorithm>
#include<string>

using namespace std;

bool Bool(string & str);
string Punct(string & str);

int main(void){

    string str;

    cout << "Enter string:";
    getline(cin, str);

    if(Bool(str) != 0)
    {
        cout << "The string is palindrom" << endl;
    }
    else
    {
        cout << "The string isn't palindorm" << endl;
    }



    return 0;
}

bool Bool(string & str)
{
    string shstr;

    shstr = Punct(str);
    int high = shstr.size() - 1, low = 0;

    while(high != low)
    {
        if(shstr[low] != shstr[high])
        {
            return false;
        }
        low++;
        high--;
    }

    return true;

}

string Punct(string & str)
{
    string Ex;
    for(int i = 0; i != str.size(); i++)
    {
        if(ispunct(str[i]) == 0 && isspace(str[i]) == 0)
        {
            Ex.push_back(tolower(str[i]));
        }
    }
    return Ex;
}
