#include<iostream>
#include<time.h>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<list>
#include<ctime>
#include<algorithm>
#define SIZE 1000000
using namespace std;

int main(void){

    vector<int> vio(SIZE);

    for(int i = 0; i != SIZE; i++)
    {
        vio[i] = 1 + rand() % 100;
    }
    vector<int> vi(vio);
    list<int> li(vio.begin(), vio.end());


    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    copy(vio.begin(), vio.end(), li.begin());
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
