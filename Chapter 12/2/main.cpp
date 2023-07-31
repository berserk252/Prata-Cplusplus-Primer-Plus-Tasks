#include <iostream>
#include "2.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	String a("HELLO");
	String b("world");
	String g;
	a.stringlow();
	b.stringup();
	int count = a.has('l');
	
	std::cout << count;
	
	return 0;
}
