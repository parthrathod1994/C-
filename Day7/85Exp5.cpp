#include<iostream>
#include<string>
using namespace std;
namespace nm85
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
			try
			{
				VendorFun(10, 0);
			}
			catch (int exp)
			{
				cout << "inner Int exp " << exp << endl;
			}
			catch (char *exp)
			{
				cout << "inner char* Exp " << exp << endl;
			}
			cout << "Grapes" << endl;
		}
		catch (double exp)
		{
			cout << "outer double Exp " << exp << endl;
		}
		cout << "Jack" << endl;
	}
}