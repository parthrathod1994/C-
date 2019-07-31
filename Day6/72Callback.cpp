#include<iostream>
#include<string>
using namespace std;

namespace nm72
{
	template<typename T>
	void VendorFun(T obj)
	{
		cout << "Vendor Job started with obj=" << typeid(obj).name() << endl;;
		obj();//callback
		cout << "Vendor Job completed \n";
		cout << "________________________________________________\n";
	}

	//-------------------------------------------

	void MyJob(int x, int y)
	{
		cout << "Client job with x=" << x << " and y=" << y << endl;
	}

	void main()
	{
		auto k = 100;//type inference
		int j = 200;
		//auto fnc = []() { cout << "Jack and Jill" << endl; };//lambda expression
		//auto fnc = [k,j]() { cout << "Jack and Jill k="<<k<<" and j="<<j << endl; };
		//auto fnc = [k, j]() mutable { k += 20; cout << "Jack and Jill k=" << k << " and j=" << j << endl; };
		//auto fnc = [&k, &j]()  { k += 20; cout << "Jack and Jill k=" << k << " and j=" << j << endl; };
		//auto fnc = [&k, j]() { k += 20; cout << "Jack and Jill k=" << k << " and j=" << j << endl; };
		//auto fnc = [=]() {  cout << "Jack and Jill k=" << k << " and j=" << j << endl; MyJob(k,j); };
		void(*fp)(int, int) = &MyJob;
		//auto fnc = [=]() {  cout << "Jack and Jill k=" << k << " and j=" << j << endl; fp(k, j); };
		//auto fnc = [=,&j]() {  cout << "Jack and Jill k=" << k << " and j=" << j << endl;  };
		auto fnc = [&, j]() {  cout << "Jack and Jill k=" << k << " and j=" << j << endl;  };
		VendorFun(fnc);
	}
}