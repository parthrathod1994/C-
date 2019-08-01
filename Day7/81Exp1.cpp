#include<iostream>
#include<string>
using namespace std;
namespace nm81
{
	void VendorFun(int x, int y)
	{
		cout << "Apple" << endl;
		if (0 == y)
			throw 1234;
		int k = x / y;
		cout << "Orange" << endl;
	}
	//--------------------------------------------------
	void TerminateParth()
	{
		cout << "Resources Relased in parth" << endl;
		exit(0);
	}
	void main()
	{
		set_terminate(TerminateParth);
		cout << "Resources Alloted in main" << endl;
		VendorFun(10, 0);
		cout << "Resources Released in main" << endl;
	}
}