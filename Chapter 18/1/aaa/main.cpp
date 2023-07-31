#include <iostream>
#include<initializer_list>
using namespace std;

template<typename T>
T average_list(initializer_list<T> il);
int main()
{

        auto q = average_list({15.4, 10.7, 9.0});
        cout << q << endl;

        cout << average_list({20, 30, 19, 17, 45, 38}) << endl;
        auto ad = average_list<double>({'A', 70, 65.33});
        cout << ad << endl;
    return 0;
}

template<typename T>
T average_list(initializer_list<T> il)
{
    T sum;
    int count = 0;
    for(auto i = il.begin(); i != il.end(); i++)
    {
        sum += *i;
        count++;
    }

    return sum / count;
}
