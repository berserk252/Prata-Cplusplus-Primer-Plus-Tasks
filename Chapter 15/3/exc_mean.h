// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include<stdexcept>
using namespace std;

class bad_hmean : public std::invalid_argument
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0, const string & s = "Bad argument in hmeans\n") : v1(a), v2(b), invalid_argument(s){}
    void display();
};

inline void bad_hmean::display()
{
    cout << "For function hmean(): " << endl;
    cout << "hmean(" << v1 << ", " << v2 <<"): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public std::domain_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0, const string & s = "bad argument in gmeans\n") : v1(a), v2(b), domain_error(s){}
    void display();
};

inline void bad_gmean::display()
{
    cout << "For function gmean(): " << endl;
    cout << "gmean() arguments should be >= 0\n";
    cout << "You entered:" << v1 << " " << v2 << endl;
}
