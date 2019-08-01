#include<iostream>
#include<string>
using namespace std;

//--------------------------------------------------

class CA
{
	static int count;
	int x;
public:
	CA()
	{
		count++;
		x = count;
		cout << "CA Ctor" << endl;
	}
	CA(const CA& par)
	{
		count++;
		x = count;
		cout << "CA Copy" << endl;
	}
	~CA()
	{
		cout << "CA D-tor x="<<x << endl;
	}
};
int CA::count = 0;

void main()
{
	int x = 10;
	cout << "Mango" << endl;
	try
	{
		CA obj;
		if (10 == x)
			throw obj;
	}
	catch (int exp)
	{
		cout << "exp " << exp << endl;
	}
	catch (CA exp)
	{
		cout << "CA exp " << endl;
	}
	cout << "Jack" << endl;
}
