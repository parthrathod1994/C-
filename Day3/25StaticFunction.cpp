#include<iostream>
using std::cout;
using std::endl;
namespace nm25
{
	class CA
	{
	public:
		static void fun1()
		{
			cout << "CA::fun1" << endl;
		}
		static void fun2()
		{
			cout << "CA::fun2" << endl;
		}
	};

	class CB :public CA
	{
	public:
		static void fun2()
		{
			cout << "CB::fun2" << endl;
		}
		static void fun3()
		{
			cout << "CB::fun3" << endl;
		}
	};

	void main()
	{
		CA obj1;
		CB obj2;
		CA *ptr1 = NULL;
		CB  *ptr2 = NULL;

		CA::fun1();
		CA::fun2();
		cout << "____________________________\n";
		CB::fun1();
		CB::fun2();
		CB::fun3();
		cout << "____________________________\n";
		obj1.fun1();
		obj1.fun2();
		cout << "____________________________\n";
		obj2.fun1();
		obj2.fun2();
		obj2.fun3();
		cout << "____________________________\n";
		ptr1->fun1();
		ptr1->fun2();
		cout << "____________________________\n";
		ptr2->fun1();
		ptr2->fun2();
		ptr2->fun3();
		cout << "____________________________\n";
	}
}