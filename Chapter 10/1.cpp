#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

class bank{
	private:
		string name;
		string accNum;
		float bal;
	
	public:
		void show() const;
		void add(float n);
		void minus(float n);
		void setName(string a);
		void setAcc(string a);
		void setbal(float a);
};

int main(void)
{
	bank g;
	
	g.setName("Armen Mirakyan");
	g.setAcc("26540");
	g.setbal(0.0);
	
	g.show();
	
	return 0;
}

void bank::show() const
{
	cout << name << " account num is " << accNum << " total value is " << bal << endl;
}

void bank::setName(string a)
{
	name = a;	
}

void bank::add(float n)
{
	bal += n;
}

void bank::minus(float n)
{
	bal -= n;
}

void bank::setAcc(string a)
{
	accNum = a;
}

void bank::setbal(float a)
{
	bal = a;
}
