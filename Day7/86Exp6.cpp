#include<iostream>
#include<string>
using namespace std;
namespace nm86
{
	void VendorFun(int x, int y)
	{
		cout << "Apple" << endl;
		if (0 == y)
			throw 100;
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
				//throw 400;
				throw;//rethrow
			}
			cout << "Grapes" << endl;
		}
		catch (int exp)
		{
			cout << "outer int Exp " << exp << endl;
		}
		cout << "Jack" << endl;
	}
}