#include<iostream>
using namespace std;
namespace nm03
{
	void main1()
	{
		int x = 10;
		int &y = x;

		cout << "&x=" << &x << endl;
		cout << "&y=" << &y << endl;
	}


	int i = 100;
	int *getAddr()
	{
		return &i;
	}
	int & getRef()
	{
		return i;
	}
	//:: scope resolution operator
	void main2()
	{
		//int i = 123;
		cout << "i=" << i << endl;
		*getAddr() = 999;
		cout << "i=" << i << endl;
		getRef() = 888;
		cout << "i=" << i << endl;
	}


	int arr[] = { 11,22,33,44,55 };

	int & getElem(int index)
	{
		return arr[index];
	}

	void main3()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "arr[" << i << "]=" << arr[i] << endl;
		}
		getElem(2) = 999;
		cout << "___________________________________\n";
		for (int i = 0; i < 5; i++)
		{
			cout << "arr[" << i << "]=" << arr[i] << endl;
		}
	}





	void main()
	{

	}
}