#include"3.h"

void golf::sethandicap(int hc)
{
	this->handicap = hc;
}
void golf::showgolf()
{
	std::cout << this->fullname << " " << this->handicap << "\n";
}

