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

vector<int> Lotto(int num_range, int counter);

int main(void){

    int num_range, counter;

    cout << "Enter numbers range and how many numbers it have to be there:";
    cin >> num_range >> counter;

    vector<int> arr = Lotto(num_range, counter);

    for(int i = 0; i != counter; i++)
    {
        cout << arr[i];
    }

    return 0;
}

vector<int> Lotto(int num_range, int counter)
{

    vector<int> arr(num_range);

    for(int i = 0; i != num_range; i++)
    {
        arr[i] = i;
    }

    random_shuffle(arr.begin(), arr.end());

    vector<int> ret(counter);
    for(int i = 0; i != counter; i++)
    {
        ret[i] = arr[i];
    }

    return ret;

}

