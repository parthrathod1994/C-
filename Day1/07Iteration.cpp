#include<iostream>
using namespace std;

namespace nm07
{

	void main1()
	{
		int sum = 0;
		for (int i = 1; i <= 5; i++)
		{
			cout << (sum = sum * 10 + i) << endl;
		}
		sum = 0;
		for (int i = 1; i <= 5; i++)
		{
			cout << (sum = sum * 10 + 1, sum*i) << endl;
		}

	}

	void main2()
	{
		int x = 15;
		int y = 50;
		while (x != y)
		{
			if (x > y)
				x -= y;
			if (y > x)
				y -= x;
		}
		cout << "THE GCD is " << x << endl;
	}

	void rev(int val)
	{
		cout << val % 10;
		if (val > 9)
			rev(val / 10);
	}
	void main3()
	{
		rev(345);
		cout << endl;
	}



	/*
	1 = 1!
	2 = 2!
	145= 1! + 4! + 5!
	? 40585
	*/
	void main()
	{

	}
}