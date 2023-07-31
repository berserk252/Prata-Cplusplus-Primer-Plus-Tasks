#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

class Move
{
	private:
		double x;
		double y;
	public:
		Move(double a = 0, double b = 0);
		void showmove() const;
		Move add(const Move &m);
		void reset(double a = 0, double b = 0);
		double getX() const;
		double getY() const;
};

int main(void)
{
	Move m{20,30};
	Move k{20,30};
	
	m.add(k);
	m.showmove();
	
	m.reset();
	m.showmove();
	
	
	return 0;
}

Move::Move(double a, double b)
{
	this->x = a;
	this->y = b;
}

Move Move::add(const Move &m)
{
	this->x += m.getX();
	this->y += m.getY();
	return *this;
}

void Move::reset(double a, double b)
{
	this->x = a;
	this->y = b;
}

void Move::showmove() const
{
	cout << "The x is " << this->x <<endl; 
	cout << "The y is " << this->y <<endl;
}

double Move::getX() const
{
	return x;
}

double Move::getY() const
{
	return y;
}
