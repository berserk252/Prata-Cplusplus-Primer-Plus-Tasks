#include"1.h"
#include<iostream>
#include<cstring>

Cow::Cow()
{
	name[0] = '\0';
	hobby = nullptr;
	weight = 0.0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
	strcpy(name, nm);
	hobby = new char [20];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow & c)
{
	strcpy(name, c.name);
	hobby = new char [20];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	strcpy(name, c.name);
	hobby = new char [20];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	std::cout << "The cow name is " << name << std::endl;
	std::cout << "The hobby is " << hobby << std::endl;
	std::cout << "The weight is " << weight << std::endl;
}
