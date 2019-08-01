#include<iostream>
#include<string>
using namespace std;

namespace nm83
{
	void VendorFun(int x, int y)
	{
		cout << "Apple" << endl;
		if (0 == y)
			throw 3.14;
		int k = x / y;
		cout << "Orange" << endl;
	}
	//--------------------------------------------------

	void main()
	{
		cout << "Mango" << endl;
		try
		{
			VendorFun(10, 0);
		}
		catch (int exp)
		{
			cout << "Int exp " << exp << endl;
		}
		catch (double exp)
		{
			cout << "double Exp " << exp << endl;
		}
		cout << "Jack" << endl;
	}
}