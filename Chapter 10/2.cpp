#include<iostream>
#include<string>
#include<cmath>
#include<vector>

#define LIMIT 25

using namespace std;
class Person{
	private:
		string lname;
		char fname[LIMIT];
	public:
		Person() {lname = ""; fname[0] = '\0';}
		Person(const string &ln, const char * fn = "Heyyou") {
			lname = ln;
			for(int i = 0; i < LIMIT; i++)
			{
				fname[i] = fn[i];
			}
		}
		
		void Show() const;
		void FormalShow() const;
};

int main(void)
{
	Person one;
	Person two("Smythecraft");
	
	Person three("Dimwiddy", "Sam");
	
	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;
	
	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;
	
	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;
	return 0;
}


void Person::Show() const{
	cout << fname << " " << lname << endl;
}

void Person::FormalShow() const{
	cout << lname << " " << fname << endl;
}
