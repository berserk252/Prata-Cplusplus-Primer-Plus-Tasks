#ifndef M_7
#define M_7
#include <iostream>
class complex
{
	private:
		float a;
		float b;
	public:
		complex();
		complex(double r, double m);
		void set(double a, double b);
		friend complex operator+(const complex & c1, const complex & c2); 
		friend complex operator-(const complex & c1, const complex & c2); 
		friend complex operator*(const complex & c1, const complex & c2); 
		friend complex operator*(double d, const complex & c2); 
		friend complex operator~(const complex & c);
		friend std::ostream & operator<<(std::ostream & os, 
		const complex & s);
		friend std::istream & operator>>(std::istream & is, complex & c);
		
		
};
#endif
