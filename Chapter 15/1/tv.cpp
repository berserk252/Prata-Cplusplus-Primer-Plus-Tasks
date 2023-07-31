// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "tv.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "DVD") << endl;
    }
}

void Remote::settings() const
{
	using std::cout;
	using std::endl;
	cout << "Remote is set to the " <<
		(mode == Tv::TV ? "TV" : "VCR");
	cout << " and is in " <<
		(mode2 == Normal ? "Normal" : "Interactive") << " mode" << endl;
}

void Tv::change_Rmode(Remote & k) const
{
	if (On == state && k.mode2 == Remote::Interactive)
		k.mode2 = Remote::Normal; // is this OK?
	else if (On == state && k.mode2 == Remote::Normal)
		k.mode2 = Remote::Interactive;
	else
		return;
}
