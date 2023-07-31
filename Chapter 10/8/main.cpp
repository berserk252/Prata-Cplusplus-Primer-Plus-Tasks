#include "8.h"
void pf(Item &i);

int main(int argc, char** argv) {
	Item b{"Armen", 50};
	List h;
	
	cout << h.isempty() << endl;
	cout << h.isfull() << endl;
	
	h.add(b);
	cout << h.isempty() << endl;
	h.visit(pf);
	
	
		
	
	return 0;
}

void pf(Item &i)
{
	cout << i.name << " " << i.p;
}
