#include"1.h"
#include <iostream>
#include <cstring>

Cd::Cd(char *s1, char * s2, int n, double x)
{
	performers = new char[sizeof(s1) + 1];
	label = new char[sizeof(s2) + 1];
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selection = n;
	playtime = x;
	
}

Cd::Cd(const Cd & d)
{
	performers = new char[sizeof(d.performers) + 1];
	label = new char[sizeof(d.label) + 1];
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selection = d.selection;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[60];
	label = new char[20];
	performers[0] = '\0';
	label[0] = '\0';
	selection = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}

void Cd::Report() const
{
	std::cout << "The performers is:" <<performers << std::endl;
	std::cout << "The label is:"<< label << std::endl;
	std::cout << "The selection is:"<< selection << std::endl;
	std::cout << "The play time is:" <<playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d)
{
	delete [] performers;
	delete [] label;
	performers = new char[60];
	label = new char[20];
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selection = d.selection;
	playtime = d.playtime;
	
}
//Classic method


Classic::Classic(char *so, char *s1, char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	song = new char[45];
	std::strcpy(song, so);
}

Classic::Classic() : Cd()
{
	song = new char[45];
	song[0] = '\0';
}
void Classic::Report() const
{
	Cd::Report();
	std::cout << "The song name is:" << song << std::endl;
}

Classic::Classic(const Classic & d) : Cd(d)
{
	song = new char[45];
	std::strcpy(song, d.song);
}

Classic::~Classic()
{
	delete [] song;
}

Classic & Classic::operator=(const Classic & d)
{
	delete [] song;
	song = new char[45];
	Cd::operator=(d);
	std::strcpy(song, d.song);
}
