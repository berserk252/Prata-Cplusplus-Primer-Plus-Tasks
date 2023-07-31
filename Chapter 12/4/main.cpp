#include <iostream>
#include"4.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Stack a, b;
	Item item = 44;
	a.push(item);
	item = 35;
	a.push(item);
	item = 44;
	b = a;
	b.pop(item);
	std::cout << item;
	

	return 0;
}
