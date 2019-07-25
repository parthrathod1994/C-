#include<iostream>
using std::cout;
using std::endl;
namespace nm19
{
	class CA
	{
		int x = 10;
	public:
		void fun1()
		{
			cout << "\t\tCA::fun1" << endl;
		}
		virtual void fun2()
		{
			cout << "\t\tCA::fun2" << endl;
		}
		virtual void fun3()
		{
			cout << "\t\tCA::fun3" << endl;
		}
	};

	void main1()
	{
		//typedef void(*Ravi)(void);
		using Ravi = void(*)();
		CA obj;
		cout << sizeof(obj) << endl;
		//((void(*)())*(long*)*(long*)&obj)();
		//step 1 reach the vptr
		long * vptr = (long*)&obj;
		//step 2 reach the vtable
		long* vtable = (long*)*vptr;
		//step 3 reach the function
		Ravi fp1 = (Ravi)*vtable;
		Ravi fp2 = (Ravi)vtable[0];
		//step 4 callback
		fp1();
		fp2();

	}


	class CB :public CA
	{
	public:
		virtual void fun4()
		{
			cout << "\t\tCB::fun4" << endl;
		}
		virtual void fun3()
		{
			cout << "\t\tCB::fun3" << endl;
		}
	};
	void main()
	{
		CA obj;
		CB obj1;
		long * vptr = (long*)&obj;
		long* vtable = (long*)*vptr;
		cout << "CA::VFTable=" << vtable << endl;
		((void(*)())vtable[0])();
		((void(*)())vtable[1])();

		long * vptr1 = (long*)&obj1;
		long* vtable1 = (long*)*vptr1;
		cout << "CB::VFTable=" << vtable1 << endl;
		((void(*)())vtable1[0])();
		((void(*)())vtable1[1])();
		((void(*)())vtable1[2])();
	}
}