#include<iostream>
#include<string>
using namespace std;
namespace nm67
{
	template<typename T>
	void VendorFun(T obj)
	{
		cout << "Vendor Job started with obj=" << typeid(obj).name() << endl;;
		obj();//callback
		cout << "Vendor Job completed \n________________________________________________\n";

	}

	//-------------------------------------------
	//function
	void ClientFun()
	{
		cout << "Client job done " << endl;
	}
	//FUNCTOR or FUNCTION OBJECTS
	class FUNC
	{
	public:
		void operator()()
		{
			cout << "functor called " << endl;
		}
	};
	//	fnc();//fnc.operator()();

	void main()
	{
		VendorFun(&ClientFun);
		FUNC fnc;
		VendorFun(fnc);
	}
}