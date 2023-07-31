#define LEN 40
#include<iostream>

using namespace std;

class golf{
	private:
		char fullname[LEN];
		int handicap;
	public:	
		golf(const char *name, int hc) {
				for(int i = 0; i < LEN; i++)
				{
					this->fullname[i] = name[i];
				}
				this->handicap = hc;
		};
		golf(){
				std::cout << "Enter the name of the player:";
				std::cin >> this->fullname;
				std::cout << "Enter the handicap:";
				std::cin >> this->handicap;
		};
		void sethandicap(int hc);
		void showgolf();			
};

