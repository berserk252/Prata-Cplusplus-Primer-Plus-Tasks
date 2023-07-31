#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#define SIZE 10
using namespace std;

int main(int argc, char *argv[]){

    ofstream fout(argv[1]);
    char s[50];

    if(fout.is_open())
    {
        cout << "Enter string:";
        cin.getline(s, 50);
        fout << s;
    }
    else{
        cout << "couldnt open the file\n";
        exit(1);
    }

    system("pause");
}
