#include <iostream>

using namespace std;



int main()
{
    auto lya = [](int x)->int {return x * x;};

    cout << lya(4);
    return 0;
}
