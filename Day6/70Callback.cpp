#include<iostream>
#include<string>
using namespace std;
namespace nm70
{
	template<typename T>
	void VendorFun(T obj)
	{
		cout << "Vendor Job started with obj=" << typeid(obj).name() << endl;;
		obj();//callback
		cout << "Vendor Job completed \n________________________________________________\n";

	}
	//-------------------------------------------
	void MyJob(int x, int y)
	{
		cout << "Client job with x=" << x << " and y=" << y << endl;
	}
	typedef void(*FPTR)(int, int);
	class FUNC
	{
		//capture
		int k;
		int j;
		FPTR fp;//void(*fp)(int, int);
	public:
		//FUNC(int k, int j, void(*fp)(int, int)) :k(k), j(j),fp(fp)
		FUNC(int k, int j, FPTR fp) :k(k), j(j), fp(fp)
		{
		}
		void operator()()
		{
			fp(k, j);
		}
	};

	void main()
	{
		int k = 100;
		int j = 200;
		FUNC fnc(k, j, &MyJob);
		VendorFun(fnc);
	}
}