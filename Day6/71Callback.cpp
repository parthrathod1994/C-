#include<iostream>
#include<string>
using namespace std;
namespace nm71
{
	template<typename T>
	void VendorFun(T obj)
	{
		cout << "Vendor Job started with obj=" << typeid(obj).name() << endl;;
		obj(1000);//callback
		cout << "Vendor Job completed \n________________________________________________\n";

	}
	//-------------------------------------------
	void MyJob(int x, int y)
	{
		cout << "Client job with x=" << x << " and y=" << y << endl;
	}


	using FPTR = void(*)(int, int);
	class FUNC
	{
		int k;
		FPTR fp;
	public:
		FUNC(int k, FPTR fp) :k(k), fp(fp)
		{
		}
		void operator()(int val)
		{
			k++;
			fp(k, val);
		}
	};

	void main()
	{
		int k = 100;
		FUNC fnc(k, MyJob);
		VendorFun(fnc);
	}
}