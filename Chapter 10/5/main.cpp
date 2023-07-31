#include <iostream>
#include"5.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Stack s;
	Item a;
	int n, count = 1;
	double promejutok = 0;
	
	while(count)
	{
		cout << "Enter 1(to add customer),2(to delete customer),3(to quite):";
		cin >> n;
		
		switch(n)
		{
			case 1:
				cout << "Enter the name and payment:";
				getchar();
				cin.getline(a.fullname, sizeof(a.fullname));
				cin >> a.payment;
				if(s.isfull() != 1)
				{
					s.push(a);
				}
				else
				{
					cout << "The stack is full,please try again\n";
				}
				break;
			case 2:
				if(s.isempty() != 1)
				{
					s.pop(a);
					cout << a.fullname << " " << a.payment << " was deleted from the stack\n";
					promejutok += a.payment;
					cout << promejutok << endl;
				}
				else
				{
					cout << "The stack is empty,please try again\n";
				}
				break;
			case 3:
				count = 0;
				break;
			
			default :
				cout << "Please enter the correct symbol\n";
				break;	
		}
	}
	return 0;
}
