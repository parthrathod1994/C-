#include<iostream>
using namespace std;


class CA
{
	int x = 10;//state
	int &y;//not state
public:
	CA(int &k):y(k)
	{
	}
	void Display()
	{
		x += 190;
		y += 100;
	}
	void Display() const
	{
		//x += 190;
		y += 100;
	}
};


void  main()
{
	cout << sizeof(CA) << endl;
	int k1 = 100;
	CA obj1(k1);
}