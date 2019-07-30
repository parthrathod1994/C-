#include<iostream>
using namespace std;
namespace nm49
{
	//ownership transfer
	class CA
	{
		int *i;
	public:
		CA() :i(new int(10))
		{
			cout << "CA Ctor called with i holding " << i << endl;
		}
		CA(CA & par) :i(par.i)
		{
			par.i = NULL;
			cout << "CA Copy (Transfered Ownership) i holding " << i << endl;
		}
		void fun()
		{
			cout << "fun called with i holding " << i << endl;
		}
		CA& operator=(CA par)
		{
			swap(this->i, par.i);
			return *this;
		}
		~CA()
		{
			cout << "CA D-tor called with i holding " << i << endl;
			delete i;
		}
	};

	void main1()
	{
		CA obj1;
		obj1.fun();
		CA obj2;
		obj2.fun();
		cout << "_________________________________\n";
		obj1 = obj2;
	}

}
