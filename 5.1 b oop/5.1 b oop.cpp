#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
	Money a(0, 0), b(0, 0);
	double x;
	bool res;
	do
	{
		try
		{
			res = true;
			cout << "First:" << endl; cin >> a;

			cout << endl << "Second:" << endl; cin >> b;
			cout << "x= "; cin >> x;
			cout << endl << "First sum = " << a;
			cout << "Second sum = " << b << endl;

			cout << "first - second: " << a - b << endl;
			cout << "first * x: " << a * x;
			cout << "second * x: " << b * x << endl;

			if (a == b)
			{
				cout << a.getGrn() << ", " << a.getKop() << " == " << b.getGrn() << ", " << b.getKop() << endl << endl;
			}
			if (a < b)
			{
				cout << a.getGrn() << ", " << a.getKop() << " < " << b.getGrn() << ", " << b.getKop() << endl << endl;
			}
			if (a > b)
			{
				cout << a.getGrn() << ", " << a.getKop() << " > " << b.getGrn() << ", " << b.getKop() << endl << endl;
			}

			cout << "a++  " << a++;
			cout << "result = " << a << endl;
			cout << "++a  " << ++a << endl;

			cout << "a--  " << a--;
			cout << "result = " << a << endl;
			cout << "--a  " << --a << endl;
		}
		catch (invalid_argument ex)
		{
			res = false;
			cerr << ex.what() << endl;
		}
		catch (NewException& ex)
		{
			res = false;
			cerr << ex.What() << endl;
		}
		catch (Exception* ex)
		{
			res = false;
			cerr << ex->What() << endl;
		}

	} while (!res);

}