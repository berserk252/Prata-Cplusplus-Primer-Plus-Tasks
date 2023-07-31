#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<time.h>

using namespace std;
class Plorg{
	private:
		string name;
		int CI;
	public:
		Plorg();
		Plorg(string n = "Plorga", int ci = 50){
			this->name = n;
			this->CI = ci;
		}
		void changeCI(int ci);
		string getName(void);
		int getCI(void);		
};

int main(void)
{
	Plorg a{"Narek", 15};
	a.changeCI(65);
	cout << a.getName();
	cout << a.getCI();
	return 0;
	
}

string Plorg::getName(void)
{
	return this->name;
}

int Plorg::getCI(void)
{
	return this->CI;
}

void Plorg::changeCI(int ci)
{
	this->CI = ci;
}

