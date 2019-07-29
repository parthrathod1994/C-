#include<iostream>
using  std::cout;
using  std::endl;
namespace nm46
{
	class CA
	{
		int *i;
	public:
		CA() :i(new int(100))
		{
			cout << this << " Holding i=" << i << endl;
		}
		CA& operator=(const CA& par)
		{
			//deep assignment
			cout << "Deep Assignment " << endl;
			*(this->i) = *par.i;
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
		obj1 = obj2;
		cout << "___________________________________\n";
	}
}