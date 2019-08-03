#include<iostream>
using namespace std;
namespace nm96
{
	class CA
	{
	public:
		int x = 10;
		int y = 20;
		void Display()
		{
			cout << "CA::Display" << endl;
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "___________________________\n";
		}
	};

	class CB :public CA
	{
	public:
		int a = 10;
		int b = 20;
		void Display()
		{
			cout << "CB::Display" << endl;
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "a=" << a << endl;
			cout << "b=" << b << endl;
			cout << "___________________________\n";
		}
	};

	void main()
	{
		CB objCB;
		objCB.x = 111;
		objCB.y = 222;
		objCB.a = 333;
		objCB.b = 444;
		cout << "______________________________\n";
		CA objCA;
		objCA.x = 999;
		objCA.y = 888;
		cout << "______________________________\n";
		objCA.Display();
		objCB.Display();
		cout << "______________________________\n";
		CA objCA1 = objCB;
		objCA1.Display();
		objCA = objCB;
		objCA.Display();
	}
}