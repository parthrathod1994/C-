#include<iostream>
using namespace std;
namespace nm95
{
	class CBase
	{
	public:
		CBase()
		{
			cout << "CBase Ctor" << endl;
		}
		void fun()
		{
			cout << "CBase Fun" << endl;
		}
		virtual void fun1()
		{
			cout << "CBase Fun1" << endl;
		}
		~CBase()
		{
			cout << "CBase Dtor" << endl;
		}
	};

	void main1()
	{
		try
		{
			throw new CBase();//error because not catch block to catch pointers(address)
		}
		catch (CBase cb)
		{
			cb.fun();
			cb.fun1();
		}
	}

	void main2()
	{
		try
		{
			throw *new CBase();
		}
		catch (CBase cb)
		{
			cb.fun();
			cb.fun1();
		}
	}

	void main3()
	{
		try
		{
			throw *new CBase();
		}
		catch (CBase& cb)
		{
			cb.fun();
			cb.fun1();
		}
	}

	void main4()
	{
		try
		{
			throw new CBase();
		}
		catch (CBase* cb)
		{
			cb->fun();
			cb->fun1();
		}
	}


	void main5()
	{
		try
		{
			throw new CBase();
		}
		catch (CBase* cb)
		{
			cb->fun();
			cb->fun1();
			delete cb;
		}
	}

	class CDerived :public CBase
	{
	public:
		CDerived()
		{
			cout << "CDerived Ctor" << endl;
		}
		void fun()
		{
			cout << "CDerived Fun" << endl;
		}
		virtual void fun1()
		{
			cout << "CDerived Fun1" << endl;
		}
		~CDerived()
		{
			cout << "CDerived Dtor" << endl;
		}
	};

	void main6()
	{
		try
		{
			CDerived cderived;
			throw cderived;
		}
		catch (CBase cb)
		{
			cb.fun();
			cb.fun1();
		}
	}


	void main()
	{
		try
		{
			CDerived cderived;
			throw cderived;
		}
		catch (CBase &cb)
		{
			cb.fun();
			cb.fun1();
		}



	}
}