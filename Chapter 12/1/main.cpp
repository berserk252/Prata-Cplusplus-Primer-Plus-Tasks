#include <iostream>

#include<cstring>
#include"1.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Cow a("MELO", "MALE", 40);
	Cow b = Cow(a);
	
	b.ShowCow();
	return 0;
}
