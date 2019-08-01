#include<iostream>
#include<string>
using namespace std;
namespace nm78
{
	namespace Sachin
	{
		int x = 100;
		int y = 200;
		int z = 300;
	}

	void main1()
	{
		using namespace Sachin;
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "z=" << z << endl;
	}

	void main2()
	{
		using Sachin::x;
		cout << "x=" << x << endl;
	}
	namespace Saurav
	{
		int a = 111;
		int b = 222;
		int z = 333;
	}

	void main3()
	{
		using namespace Sachin;
		using namespace Saurav;
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "a=" << a << endl;
		cout << "b=" << a << endl;
		cout << "z=" << Sachin::z << endl;
		cout << "z=" << Saurav::z << endl;
	}

	void main4()
	{
		cout << "z=" << Sachin::z << endl;
		cout << "z=" << Saurav::z << endl;
	}

	namespace Cat
	{
		int a = 111;
		int b = 222;

	}
	namespace Cat
	{
		int x = 100;
		int y = 200;
	}

	void main5()
	{
		using namespace Cat;
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		cout << "a=" << a << endl;
		cout << "b=" << a << endl;
	}


	namespace Dog
	{
		int k = 123;
		int j = 321;
	};

	namespace Kennel
	{
		using namespace Dog;
		int a = 111;
		int b = 222;

	}

	void main6()
	{
		using namespace Kennel;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "k=" << k << endl;
		cout << "j=" << j << endl;
	}


	namespace Rahul
	{
		int k = 123;
		int j = 321;
		namespace Dravid
		{
			int a = 111;
			int b = 222;
		}
	}

	void main()
	{
		using namespace Rahul;
		using namespace Rahul::Dravid;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout << "k=" << k << endl;
		cout << "j=" << j << endl;
	}
}