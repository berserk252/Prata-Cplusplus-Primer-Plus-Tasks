#include <iostream>
#include<string>
#include <fstream>
#include"5.h"

using namespace std;

int main()
{

    const char * file = "guests";
    char ch;
    int temp;

    ifstream fin;
    fin.open(file);
    int count = 0;

    abstr_emp *pc[10];

    if (fin.is_open())
    {
        int classtype;
		while((fin >> classtype).get(ch))
		{
			switch(classtype)
			{
				case abstr_emp::Employee:
					pc[count] = new employee;
					pc[count++]->GetAll(fin);
					break;
				case abstr_emp::Manager:
					pc[count] = new manager;
					pc[count++]->GetAll(fin);
					break;
				case abstr_emp::Fink:
					pc[count] = new fink;
					pc[count++]->GetAll(fin);
					break;
				case abstr_emp::Highfink:
					pc[count] = new highfink;
					pc[count++]->GetAll(fin);
					break;
			}
		}

		cout << "Here is your current employee list: " << endl;
		for (int i = 0; i < count; i++)
		{
			pc[i]->ShowAll();
			cout << endl;
		}
    }


		fin.close();
    /////////////////////////////

    ofstream fout(file, ios::out | ios::app);
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    char q;
    while(count < 10)
    {
        cout << "Enter type of employee to input in file(You can input 10 characters)\n";
        cout << "'e' = employee  'm' = manager\n'f' = fink  'h' = highfink\n'q' = quite:";
        cin >> q;
        char ch;
        while(cin.get(ch) && ch != '\n')
            continue;

        switch(q)
        {
            case 'e':
               pc[count] = new employee;
               pc[count]->SetAll();
               count++;
               break;

            case 'm':
               pc[count] = new manager;
               pc[count]->SetAll();
               count++;
               break;

            case 'f':
               pc[count] = new fink;
               pc[count]->SetAll();
               count++;
               break;

            case 'h':
               pc[count] = new highfink;
               pc[count]->SetAll();
               count++;
               break;
            case 'q':
                temp = count;
                count = 10;
               break;
        }
    }

    cout << "Here's our updated list: " << endl;
	for(int i = 0; i < temp; i++)
	{
		pc[i]->ShowAll();
		cout << endl;
		pc[i]->WriteAll(fout);
	}

	fout.close();
    return 0;

}
