// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>

#include <stdexcept>
class bad_hmean : public std::logic_error
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0, const std::string & s = "Bad argument in Hmean\n");
    void mesg();
};

bad_hmean::bad_hmean(double a, double b, const std::string & s) : std::logic_error(s),v1(a), v2(b)
{

}

inline void bad_hmean::mesg()
{
   std::cout << bad_hmean::what();
}

class bad_gmean : public std::logic_error
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0, const std::string & s = "Bad argument in Gmean\n");
    const char * mesg();
};

bad_gmean::bad_gmean(double a, double b, const std::string & s) : std::logic_error(s), v1(a), v2(b)
{

}

inline const char * bad_gmean::mesg()
{
   return bad_gmean::what();
}
