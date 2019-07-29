#include<iostream>
using namespace std;
namespace nm32
{
	struct A
	{
		int x = 1;
		int y = 2;
		virtual void fun1()
		{
			cout << "\t\tCA::fun1\n";
		}
	};
	struct B
	{
		int x = 3;
		int y = 4;
		virtual void fun1()
		{
			cout << "\t\tCB::fun1\n";
		}
	};
	struct C
	{
		int x = 5;
		int y = 6;
		virtual void fun2()
		{
			cout << "\t\tCC::fun2\n";
		}
	};
	struct D :public A, public B
	{
		int x = 7;
		int y = 8;
		C obj;
		virtual void fun3()
		{
			cout << "\t\tCD::fun3\n";
		}
	};


	void main()
	{
		using FPTR = void(*)();
		D obj;
		cout << sizeof(obj) << endl;
		cout << "_________________________\n";
		long* ptr = (long*)&obj;
		cout << *ptr << endl;//vptr1 inherited for A
		((FPTR)((long*)(*ptr))[0])();
		((FPTR)((long*)(*ptr))[1])();//virtual function of D
		ptr++;
		cout << *ptr << endl;//1
		ptr++;
		cout << *ptr << endl;//2
		ptr++;
		cout << *ptr << endl;//vptr2 inherited for B
		((FPTR)((long*)(*ptr))[0])();
		ptr++;
		cout << *ptr << endl;//3
		ptr++;
		cout << *ptr << endl;//4
		ptr++;
		cout << *ptr << endl;//7
		ptr++;
		cout << *ptr << endl;//8
		ptr++;
		cout << *ptr << endl;//obj vptr contained for c
		((FPTR)((long*)(*ptr))[0])();
		ptr++;
		cout << *ptr << endl;//5
		ptr++;
		cout << *ptr << endl;//6
		ptr++;
	}
}