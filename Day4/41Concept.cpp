#include<iostream>
using namespace std;

namespace nm41
{
	class CA
	{
	public:
		CA()
		{
			cout << this << " Default Ctor " << endl;
		}
		CA(const CA & par)
		{
			cout << this << " copy called " << endl;
		}
		~CA()
		{
			cout << this << " Released " << endl;
		}
	};


	void fun1(CA par)
	{
		cout << " Recived " << &par << endl;
	}

	void fun2(CA& par)
	{
		cout << " Recived " << &par << endl;
	}

	void main()
	{
		CA obj1;
		cout << "&obj1=" << &obj1 << endl;
		fun2(obj1);
		cout << "______________________________________\n";
	}
}