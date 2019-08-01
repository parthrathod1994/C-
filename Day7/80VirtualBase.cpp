#include<iostream>
#include<string>
using namespace std;
namespace nm80
{
	class CA
	{
	public:
		virtual void fun1()
		{
			cout << "\t\tCA::fun1\n";
		}
		int x = 100;
	};
	class CB :virtual public CA
	{
	public:
		int y = 200;

		virtual void fun2()
		{
			cout << "\t\tCB::fun2\n";
		}
		virtual void fun1()
		{
			cout << "\t\tCB::fun1\n";
		}
	};
	class CC :virtual public CA
	{
	public:
		int c = 300;

		virtual void fun3()
		{
			cout << "\t\tCC::fun3\n";
		}
		virtual void fun1()
		{
			cout << "\t\tCC::fun1\n";
		}
	};
	class CD :public CB, public CC
	{
	public:
		int a = 400;
		virtual void fun4()
		{
			cout << "\t\tCB::fun4\n";
		}
		virtual void fun1()
		{
			cout << "\t\tCD::fun1\n";
		}
	};

	void main1()
	{
		CD obj;
		obj.x = 9000;

		//cout << sizeof(obj) << endl;
		long* ptr = (long*)&obj;
		cout << *ptr << endl;
		((void(*)())(((long*)(*ptr))[0]))();
		((void(*)())(((long*)(*ptr))[1]))();
		ptr++;
		cout << *ptr << "\t\t" << ((long*)(*ptr))[1] << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		((void(*)())(((long*)(*ptr))[0]))();
		//((void(*)())(((long*)(*ptr))[1]))();//error
		ptr++;
		cout << *ptr << "\t\t" << ((long*)(*ptr))[1] << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		((void(*)())(((long*)(*ptr))[0]))();
		//((void(*)())(((long*)(*ptr))[1]))();//error
		ptr++;
		cout << *ptr << endl;

	}

	void main()
	{

		CA obj;
		cout << "____________________________________________\n";
		cout << "CA size =" << sizeof(CA) << endl;
		cout << "____________________________________________\n";
		long * vptr = (long*)&obj;
		long * vtable = (long*)*vptr;
		cout << "CA::vtable=" << vtable << endl;
		((void(*)())vtable[0])();
		vptr++;
		cout << "x=" << *vptr << endl;
		cout << "____________________________________________\n";
		CB obj1;
		cout << "CB size =" << sizeof(CB) << endl;
		cout << "____________________________________________\n";
		vptr = (long*)&obj1;
		vtable = (long*)*vptr;
		cout << *vptr << endl;
		((void(*)())vtable[0])();
		vptr++;
		cout << *vptr << "\t\t" << ((long*)(*vptr))[1] << endl;
		vptr++;
		cout << *vptr << endl;
		vptr++;
		cout << *vptr << endl;
		vtable = (long*)*vptr;
		((void(*)())vtable[0])();
		vptr++;
		cout << *vptr << endl;
		cout << "____________________________________________\n";
		CC obj2;
		cout << "CC size =" << sizeof(CC) << endl;
		cout << "____________________________________________\n";
		vptr = (long*)&obj2;
		vtable = (long*)*vptr;
		cout << *vptr << endl;
		((void(*)())vtable[0])();
		vptr++;
		cout << *vptr << "\t\t" << ((long*)(*vptr))[1] << endl;
		vptr++;
		cout << *vptr << endl;
		vptr++;
		cout << *vptr << endl;
		vtable = (long*)*vptr;
		((void(*)())vtable[0])();
		vptr++;
		cout << *vptr << endl;
		cout << "____________________________________________\n";
		main1();
	}
}