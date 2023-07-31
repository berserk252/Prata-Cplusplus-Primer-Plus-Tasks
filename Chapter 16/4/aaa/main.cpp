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

int reduce(long arr[], int n);

int main(void){
    int n = 10;
    long arr[n] = {12, 15, 6, 12, 15, 4, 3, 2, 9, 15};
    int counter;

    counter = reduce(arr, n);

    cout << counter << endl;

    return 0;
}

int reduce(long arr[], int n)
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
