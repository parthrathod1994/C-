#include<iostream>
using  std::cout;
using  std::endl;

class CA
{
	int *i;
public:
	CA() :i(new int(100))
	{
		cout << this << " Holding i=" << i << endl;
	}
	CA(const CA& par) :i(new int(*par.i))
	{
		cout << this << " Deep Copy holding i=" << i << endl;
	}
	//CA& operator=(const CA& par)
	//{
	//	this->CA::~CA();
	//	this->CA::CA(par);//does not work 
	//	return *this;
	//}

	CA& operator=(CA par)
	{
		cout << "Assignment doing copy swap" << endl;
		std::swap(this->i, par.i);
		return *this;
	}
	void fun()
	{
		cout << "The Value of *i=" << *i << endl;
	}
	~CA()
	{
		cout << this << " Releasing i=" << i << endl;
		delete i;
	}
};

void main()
{
	CA obj1;
	CA obj2;
	CA obj3(obj2);
	obj1 = obj2;
	cout << "___________________________________\n";
}