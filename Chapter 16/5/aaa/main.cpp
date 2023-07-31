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
template<class T>
int reduce(T arr[], int n);

int main(void){
    int n = 10;
    string arr[n] = {"arr", "arr", "arr", "arr", "asdf", "bolno", "klor", "kkk", "kkk", "4578"};
    int counter;

    counter = reduce(arr, n);

    cout << counter << endl;

    return 0;
}

template<class T>
int reduce(T arr[], int n)
{

    int counter = 0;

    sort(arr, arr + 10);
    auto a = unique(arr, arr + 10);

    for(auto i = arr; i != a; i++)
    {
        cout << *i << " ";
        counter++;
    }

    cout << endl;

    return counter;
}
