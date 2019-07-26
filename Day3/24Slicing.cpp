#include<iostream>
using std::cout;
using std::endl;
namespace nm24
{
	class CA
	{
	public:
		int x = 10;
		int y = 20;
	public:
		void nFun()
		{
			cout << "CA N-Fun x=" << x << " y=" << y << endl;
		}
		virtual void vFun()
		{
			cout << "CA V-Fun x=" << x << " y=" << y << endl;
		}
	};

	class CB :public CA
	{
	public:
		int a = 100;
		int b = 200;
		void nFun()
		{
			cout << "CB N-Fun x=" << x << " y=" << y << " a=" << a << " b=" << b << endl;
		}
		virtual void vFun()
		{
			cout << "CB V-Fun x=" << x << " y=" << y << " a=" << a << " b=" << b << endl;
		}
	};

	void main()
	{
		CB objCb;
		long *ptr = (long*)&objCb;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		cout << "_______________________________\n";
		CB *ptrCB = &objCb;
		ptrCB->a = 999;
		ptrCB->b = 888;
		ptrCB->x = 777;
		ptrCB->y = 666;
		ptrCB->nFun();
		ptrCB->vFun();
		cout << "_______________________________\n";
		CA* ptrCA = &objCb;
		ptrCA->x = 555;
		ptrCA->y = 444;
		ptrCA->nFun();
		ptrCA->vFun();
		cout << "_______________________________\n";
	}
}