#include<iostream>
using namespace std;
namespace nm12
{
	class CA
	{
	public:
		//state
		int x;
		int y;//normal instance members
		mutable int z; //mutable member
		const int empId;//const member
		//not a state
		static int s;
		static const int c;
		CA() :x(10), y(20), z(30), empId(10)//initilization list
		{

			cout << "CA Ctor Default \n";
		}
		//CA(int par) :x(par), y(x), z(y)//initilization list
		//CA(int par) :y(x),x(par), z(y)//initilization list
		//CA(int par) :y(par), x(y), z(y)//initilization list
		CA(int par) :y(x), z(y), x(par), empId(par + 1)//initilization list
		{
			cout << "CA Ctor One Param \n";
		}
		void Display() const
		{
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "z=" << z << endl;
			cout << "\n____________________________\n";
		}
	};
	int CA::s = 10;
	const int CA::c = 20;

	void main()
	{
		CA obj1;
		CA obj2(100);
		obj1.Display();
		obj2.Display();

		CA::s = 100;
		obj1.s = 999;
		int k = CA::c;
		int j = obj2.c;
	}
}