#ifndef list_h
#define list_h
#define SIZE 100
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<time.h>
using namespace std;
struct Item{
	string name;
	int p;
};

class List{
	private:
		Item item[SIZE];
		int count = 0;
	public:
		bool isempty();
		bool isfull();
		void add(Item i);
		void visit(void (*pf)(Item &));
};
#endif
