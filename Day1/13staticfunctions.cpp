#include<iostream>
using namespace std;

namespace nm13
{
	class CA
	{
	public:
		int x;
		static int s;
		CA() :x(10)
		{
		}
		void fun()
		{
			cout << "x=" << x << endl;
			cout << "s=" << s << endl;
		}
		static void sFun()
		{
			cout << "s=" << s << endl;
		}
	};
	int CA::s = 10;


	void main()
	{
		CA obj1;

		obj1.x = 999;
		obj1.s = 888;

		CA::s = 994;


		obj1.fun();

		obj1.sFun();
		CA::sFun();
	}
}