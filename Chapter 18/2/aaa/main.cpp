#include <iostream>

using namespace std;
class Cpmv
{
public:
    struct Info
    {
        string qcode;
        string zcode;
    };
private:
    Info *pi;
public:
    Cpmv() = default;
    Cpmv(string q, string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && mv);
    ~Cpmv();
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv & obj) const;
    void Display() const;
};

int main()
{
    cout << "a1\n";
    Cpmv a1("zyzz", "bad");
    cout << "a2\n";
    Cpmv a2(" Muenster", " boy");
    cout << "a3\n";
    Cpmv a3(move(a1 + a2));

    a3.Display();
    return 0;
}

Cpmv::Cpmv(string q, string z)
{
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
    cout << "COPY\n";
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
    pi = new Info;
    cout << "MOVE\n";
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
    delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;

    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
    pi = mv.pi;
    mv.pi = nullptr;

    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    pi->qcode += obj.pi->qcode;
    pi->zcode += obj.pi->zcode;

    return *this;
}

void Cpmv::Display() const
{
   cout << "qcode: " << pi->qcode << endl;
   cout << "zcode: " << pi->zcode << endl;
}
