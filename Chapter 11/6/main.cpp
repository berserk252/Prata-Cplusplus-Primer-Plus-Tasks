
#include<iostream>
#include "6.h"

const int ArrSize = 6;
Stonewt reference(11,0);

int main(void)
{
	using namespace std;

	Stonewt stArr[6] =
	{
		Stonewt(11,4),
		Stonewt(200),
		Stonewt(150)
	};
	
	double pounds;
	for (int i = 3; i < ArrSize; i++)
	{
		cout << "Enter the number of pounds for the Stonewt object";
		cout << " at position " << i + 1 << ": ";
		cin >> pounds;
		stArr[i] = Stonewt(pounds);
	}

	Stonewt min = stArr[0];
	Stonewt max = stArr[0];
	int count = 0;
	for (int i = 0; i < ArrSize; i++)
	{
		if (stArr[i] >= reference)
			count++;
	
		if (stArr[i] > max)
			max = stArr[i];
		else if (stArr[i] < min)
			min = stArr[i];
	}

	cout << "The heaviest object weighed: " << max << " pounds." << endl;
	cout << "The lightest object weighed: " << min << " pounds." << endl;
	cout << "The number of objects that weighed above " << reference;
	cout << " pounds was " << count << endl;

	return 0;
}
