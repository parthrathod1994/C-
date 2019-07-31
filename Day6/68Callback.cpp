#include<iostream>
#include<string>
using namespace std;

namespace nm68
{
	typedef void(*FPTR)();
	void VendorFun(FPTR fp)
	{
		cout << "Vendor Job started with obj=" << typeid(fp).name() << endl;;
		fp();//callback
		cout << "Vendor Job completed \n________________________________________________\n";
	}

	//-------------------------------------------
	//function
	void ClientFun()
	{
		cout << "Client job done " << endl;
	}

	void main()
	{
		VendorFun(&ClientFun);
	}
}