#include<iostream>
#include<string>
using namespace std;
namespace nm87
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

	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor" << endl;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
	};

	void main()
	{
		CA obj;
		cout << "Mango" << endl;
		try
		{
			VendorFun(10, 0);
		}
		catch (int exp)
		{
			cout << "exp " << exp << endl;
		}

		cout << "Jack" << endl;
	}
}