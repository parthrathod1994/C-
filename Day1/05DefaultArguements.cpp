#include<iostream>
using namespace std;
namespace nm05
{
	void fun1(int, int, int, int = 10);
	void fun1(int, int, int = 20, int);
	void fun1(int, int = 30, int, int);
	void fun1(int x, int y, int z, int a)
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "z=" << z << endl;
		cout << "a=" << a << endl;
		cout << "__________________________________\n";
	}
	void main1()
	{
		fun1(111, 222, 333, 444);
		fun1(111, 222, 333);
		fun1(111, 222);
		fun1(111);
	}


	void fun2(int, int = 30, int = 20, int = 10);
	void fun2(int x, int y, int z, int a)
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "z=" << z << endl;
		cout << "a=" << a << endl;
		cout << "__________________________________\n";
	}

	void main2()
	{
		fun2(111, 222, 333, 444);
		fun2(111, 222, 333);
		fun2(111, 222);
		fun2(111);
	}

	void fun3(int x, int y = 30, int z = 20, int a = 10)
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "z=" << z << endl;
		cout << "a=" << a << endl;
		cout << "__________________________________\n";
	}

	void main()
	{
		fun3(111, 222, 333, 444);
		fun3(111, 222, 333);
		fun3(111, 222);
		fun3(111);
	}

}