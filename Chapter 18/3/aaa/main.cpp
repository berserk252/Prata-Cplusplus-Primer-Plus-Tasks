/*#include <iostream>

using namespace std;

template<typename T>
long double sum_values(T value);

template<typename T, typename... Args>
long double sum_values(long double sum, T value, Args... args);

template<typename T, typename... Args>
long double sum_values(T value, Args... args);

int main()
{
    long double a = sum_values(10, 10, 10);
    cout << "a ==" << a << endl;


    return 0;
}

template<typename T>
long double sum_values(T value)
{
    cout <<"Return: " << value << endl;
    return (long double)value;
}

template<typename T, typename... Args>
long double sum_values(T value, Args... args)
{
    cout <<"FIRST CALL: " << value << endl;
    sum_values((long double)value, args...);
}

template<typename T, typename... Args>
long double sum_values(long double sum, T value, Args... args)
{
    cout <<"OTHER CALL: " << sum << endl;
    sum_values((long double)sum + (long double)value, args...);
}*/

//////////////////////////////////////
#include <iostream>

using namespace std;

template<typename T>
long double sum_values(T value);

template<typename T, typename... Args>
long double sum_values(long double sum, T value, Args... args);

template<typename T, typename... Args>
long double sum_values(T value, Args... args);

int main()
{
    long double a = sum_values(10, 10, 10);
    cout << "a == " << a << endl;

    return 0;
}

template<typename T>
long double sum_values(T value)
{
    cout <<"Return: " << value << endl;
    return static_cast<long double>(value);
}

template<typename T, typename... Args>
long double sum_values(T value, Args... args)
{
    cout <<"FIRST CALL: " << value << endl;
    return sum_values(static_cast<long double>(value), args...);
}

template<typename T, typename... Args>
long double sum_values(long double sum, T value, Args... args)
{
    cout <<"OTHER CALL: " << sum << endl;
    return sum_values(sum + static_cast<long double>(value), args...);
}
