#include<iostream>
using namespace std;

class CA
{
public:
	virtual ~CA()
	{
	}
};

class CB:public CA
{
	public:
};

class CC:public CB
{
public:
};

class CD :public CC
{
public:
};


void fun(const int *c)
{
	//if(business)
	int *f = const_cast<int*>(c);
	*f = 999;
}

void main()
{
	int x = 100;
	fun(&x);
	cout << "x=" << x << endl;
}


void main4()
{
	double d = 3.14159;
	short s =static_cast<short>( d);
	cout << "s=" << s << endl;
	cout << sizeof(s) << endl;
}

void main3()
{
	//
	CA* ptrCa = new CD();
	cout << typeid(*ptrCa).name() << endl;//RTTI
	delete ptrCa;
	CB* ptrCb = dynamic_cast<CB*>(ptrCa);
	if (ptrCb != NULL)
		cout << "Apple" << endl;
	else
		cout << "Orange" << endl;
}

void main2()
{
	 char name[] = "Serasachasadanowaladetzalazambra";
	 int *i =reinterpret_cast<int*>(name);//C-Style casting
	 cout << i << endl;
	 cout << (char*)i << endl;
}

void main1()
{
	CA* ptrCa = new CA();
	//CB* ptrCb = (CB*)ptrCa;
	CB* ptrCb = reinterpret_cast<CB*>(ptrCa);
}