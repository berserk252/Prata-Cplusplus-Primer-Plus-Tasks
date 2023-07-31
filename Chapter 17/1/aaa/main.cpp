#include<iostream>
#include<time.h>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<bitset>
#include<algorithm>
#define SIZE 10
using namespace std;

int main(void){

    char s[10];

    cout << "Enter string(10 characters and if you enter '$' the input will end)";

    cin.get(s, 10, '$');

    if(cin.peek() == '$')
    {
        cout << "YEAP";
    }
    return 0;
}
