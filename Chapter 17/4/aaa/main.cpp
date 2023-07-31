#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<bitset>
#include<algorithm>
#define SIZE 10
using namespace std;

int main(int argc, char *argv[])
{
    ifstream f1("second"), f2("first");
    ofstream f3("result");

    char ch;

    if(f1.is_open() && f2.is_open() && f3.is_open())
    {
        f1.get(ch);
        while(!f1.eof())
        {
            while(!f1.eof() && ch != '\n')
            {
                f3 << ch;
                f1.get(ch);
            }
            f3 << ' ';
            f2 >> ch;
            while(!f2.eof() && ch != '\n')
            {
                f3 << ch;
                f2.get(ch);
            }
            f3 << '\n';
            f1.get(ch);
        }
        if(!f2.eof())
        {
            f2 >> ch;
            while(!f2.eof() && ch != '\n')
            {
                f3 << ch;
                f2.get(ch);
            }
        }
    }
    else
    {
        cout << "Could't open the file\n";
        exit(1);
    }

    f1.close();
    f2.close();
    f3.close();


    return 0;
}
