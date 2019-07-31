#include<iostream>
#include<string>
#include<future>
using namespace std;
using namespace std::placeholders;

void VendorFun(std::function<void(int)> obj)//c++11 onwards
{
	cout << "Vendor Job started with obj=" << typeid(obj).name() << endl;;
	obj(100);
	cout << "Vendor Job completed \n________________________________________________\n";
}

void Myfun(int x)
{
	cout << "Myfun called with " << x << endl;
}

void MyJob(int x, int y)
{
	cout << "Client job with x=" << x << " and y=" << y << endl;
}


void main1()
{
	//auto fnc = [](int val) {cout << "Client got val=" << val << endl; };
	//std::function<void(int)> fnc = Myfun;
	std::function<void(int)> fnc =std::bind(&MyJob,_1,1000);
	VendorFun(fnc);
}



double div1(double x, double y)
{
	return x / y;
}

void main()
{
	
	cout << "1/4=" << div1(1, 4) << endl;
	cout << "2/4=" << div1(2, 4) << endl;
	cout << "3/4=" << div1(3, 4) << endl;
	cout << "4/4=" << div1(4, 4) << endl;
	cout << "_____________________________" << endl;
	std::function<double(double)> fn = std::bind(&div1, _1, 4);
	cout << "1/4=" << fn(1) << endl;
	cout << "2/4=" << fn(2) << endl;
	cout << "3/4=" << fn(3) << endl;
	cout << "4/4=" << fn(4) << endl;
	cout << "_____________________________" << endl;
	std::function<double(double,double)> fn1 = std::bind(&div1, _2, _1);
	cout << "inv of 1/4=" << fn1(1, 4) << endl;
	cout << "inv of 2/4=" << fn1(2, 4) << endl;
	cout << "inv of 3/4=" << fn1(3, 4) << endl;
	cout << "inv of 4/4=" << fn1(4, 4) << endl;
	cout << "_____________________________" << endl;
}
