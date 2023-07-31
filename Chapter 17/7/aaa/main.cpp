#include<iostream>
#include<time.h>
#include<string>
#include<cmath>
#include<cctype>
#include<vector>
#include<bitset>
#include<algorithm>
#include<fstream>
using namespace std;
void ShowStr(string & s);

class Store{
private:
    ofstream *fout;
public:
    Store(ofstream  &x) {fout = &x;}
    void operator()(const string & s);
};
void GetStrs(ifstream &fin, vector<string> &v);

int main(int argc, char *argv[])
{
    vector<string> vostr;
    string temp;

    cout << "Enter string(empty line to quit):\n";
    while(getline(cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    return 0;
}

void Store::operator()(const string & s)
{
    auto len = s.size();
    fout->write((char *)&len, sizeof(std::size_t));
    fout->write(s.data(), len);
}

void ShowStr(string &s)
{
        cout << s << endl;
}

void GetStrs(ifstream &fin, vector<string> &v)
{
    size_t len;
    string temp;

    while(fin.read((char *)&len, sizeof(std::size_t)))
    {
        char * buf = new char[len];
        fin.read(buf, len);
        temp = buf;
        v.push_back(temp);
        delete[] buf;
    }
}
