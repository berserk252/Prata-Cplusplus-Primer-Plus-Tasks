#include"5.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
//Abstr_emp methods
abstr_emp::abstr_emp() : fname(""), lname(""), job("")
{

}

abstr_emp::abstr_emp(const string & fn, const string & ln,
                  const string & j) : fname(fn), lname(ln), job(j)
{

}

void abstr_emp::ShowAll() const
{
    cout << "Name:" << fname << " " << lname << endl;
    cout << "Job:" << job << endl;
}

void abstr_emp::SetAll()
{
    cout << "Enter name:";
    cin >> fname >> lname;
    cout << "Enter "<< fname <<" " << lname << " job:";
    cin >> job;
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{

    os << "Name:" << e.fname << " " << e.lname << endl;
    os << "Job:" << e.job << endl;
    return os;
}

void abstr_emp::WriteAll(ofstream &fout) const
{
    fout << "First name: " << fname << endl;
	fout << "Last name: " << lname << endl;
	fout << "Job: " << job << endl;
}

void abstr_emp::GetAll(ifstream &fin)
{

    fin.ignore(256, ':');
    while(' ' == fin.peek())
    {
        fin.get();
    }

    getline(fin, fname);

    fin.ignore(256, ':');
    while(' ' == fin.peek())
    {
        fin.get();
    }

    getline(fin, lname);

    fin.ignore(256, ':');
    while(' ' == fin.peek())
    {
        fin.get();
    }

    getline(fin, job);
}

abstr_emp::~abstr_emp()
{

}

//employee methods

employee::employee() : abstr_emp()
{

}

employee::employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << endl;
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::WriteAll(ofstream &fout) const
{
    fout << abstr_emp::Employee << endl;
    abstr_emp::WriteAll(fout);
}

void employee::GetAll(ifstream & fin)
{
    abstr_emp::GetAll(fin);
}

// manager methods

manager::manager() : abstr_emp(), inchargeof(0)
{

}

manager::manager(const string & fn, const string & ln, const string & j, int ico) : abstr_emp(fn, ln, j)
{
    inchargeof = ico;
}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e)
{
    inchargeof = ico;
}

manager::manager(const manager & m) : abstr_emp(m)
{
    inchargeof = m.InChargeOf();
}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "In charge of manager:" << inchargeof << endl << endl;
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the charge of manager:";
    cin >> inchargeof;
}

void manager::WriteAll(ofstream &fout) const
{
    fout << abstr_emp::Manager << endl;
    abstr_emp::WriteAll(fout);
    fout << "Number of people managed: " << inchargeof << endl;
}

void manager::GetAll(ifstream & fin)
{
    abstr_emp::GetAll(fin);
    fin.ignore(256, ':');
    while(' ' == fin.peek())
        fin.get();

    fin >> inchargeof;
    fin.get();
}
// fink methods

fink::fink() : abstr_emp(), reportsto("")
{

}

fink::fink(const string & fn, const string & ln, const string & j, const string & rpo): abstr_emp(fn, ln, j), reportsto(rpo)
{

}

fink::fink(const abstr_emp & e, const string & rpo): abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink & e) : abstr_emp(e)
{
    reportsto = e.ReportsTo();
}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "Send reports to " << reportsto << endl << endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter the name who you sent reports:";
    char ch;
    while(cin.get(ch) && ch != '\n')
        continue;
    getline(cin, reportsto);
}

void fink::WriteAll(ofstream &fout) const
{
    fout << abstr_emp::Fink << endl;
    abstr_emp::WriteAll(fout);
    fout << "Reports to: " << reportsto << endl;
}

void fink::GetAll(ifstream & fin)
{
    abstr_emp::GetAll(fin);
    fin.ignore(256, ':');
    while(' ' == fin.peek())
        fin.get();
    getline(fin, reportsto);
}

highfink::highfink() : manager(), fink()
{

}

highfink::highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) : manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp & e, const string & rpo, int ico) : manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink & f, int ico) : fink(f), abstr_emp(f)
{
    manager::InChargeOf() = ico;
}

highfink::highfink(const manager & m, const string rpo): manager(m), abstr_emp(m)
{
    fink::ReportsTo() = rpo;
}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << "In charge of manager:" << manager::InChargeOf() << endl;
    cout << "Send reports to " << fink::ReportsTo() << endl << endl;
}

void highfink::SetAll()
{
    int inco;
    string rpo;
    abstr_emp::SetAll();
    cout << "Enter the charge of manager:";
    cin >> inco;
    InChargeOf() = inco;
    cout << "Enter the name who you sent reports:";
    while(getchar() != '\n')
    {
        continue;
    }
    getline(cin, ReportsTo());
}

void highfink::WriteAll(ofstream &fout) const
{
    fout << abstr_emp::Highfink << endl;
    abstr_emp::WriteAll(fout);
	fout << "Number of people managed: " << InChargeOf() << endl;
	fout << "Reports to: " << ReportsTo() << endl;
}

void highfink::GetAll(ifstream & fin)
{
    abstr_emp::GetAll(fin);
    fin.ignore(256, ':');
    fin >> InChargeOf();
    fin.ignore(256, ':');
    getline(fin, ReportsTo());
}
