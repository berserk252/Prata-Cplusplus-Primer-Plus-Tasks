#include<iostream>
#include<time.h>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<fstream>
#include<algorithm>
#define SIZE 10
using namespace std;

int main(int argc, char *argv[])
{
    ofstream fout(argv[2]);
    ifstream fin(argv[1]);
    char s[20];

    if(fin.is_open() && fout.is_open())
    {
        cout << "kk" << endl;
        while(fin.read(s, 20))
        {
            cout << s << endl;
            fout << s;
            fin.clear();
            for(int i = 0; i != 20; i++)
            {
                s[i] = '\0';
            }
        }
        fout << s;
    }
    else{
        cout << "cant open the file\n";
        exit(1);
    }

    fout.close();
    fin.close();
    system("pause");
}
