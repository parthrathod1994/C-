#include<iostream>
using namespace std;
namespace nm52
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor" << endl;
		}
		void fun()
		{
			cout << "CA Fun" << endl;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
	};

	class Wrapper
	{
		CA* ptr;
	public:
		Wrapper() :ptr(new CA())
		{
		}
		Wrapper(CA* ptr) :ptr(ptr)
		{
		}
		Wrapper(const Wrapper & par) :ptr(par.ptr)
		{
			//par.ptr = NULL;
		}
		Wrapper& operator=(Wrapper par)
		{
			swap(this->ptr, par.ptr);
			return *this;
		}
		CA* operator->()
		{
			return ptr;
		}
		~Wrapper()
		{
			delete ptr;
		}
	};

	Wrapper Make_Wraper()
	{
		return Wrapper(new CA());
	}


	void main()
	{
		Wrapper w1 = Make_Wraper();
	}

	class Wrapper1
	{
		CA* ptr;
	public:
		Wrapper1() :ptr(new CA())
		{
		}
		Wrapper1(CA* ptr) :ptr(ptr)
		{
		}

		Wrapper1(Wrapper1 & par) = delete;

		Wrapper1& operator=(Wrapper1 par) = delete;

		CA* operator->()
		{
			return ptr;
		}
		~Wrapper1()
		{
			delete ptr;
		}
	};





	void main3()
	{
		Wrapper1 w1;
		Wrapper1 w2 = new CA();


		//w1.operator->()->fun();
		w1->fun();
	}

	void main2()
	{
		Wrapper w1;
		Wrapper w2 = new CA();

		//Wrapper w3(w2);

		//w1.operator->()->fun();
		w1->fun();
	}

	void main1()
	{
		//CA obj1;
		//CA *ptr = new CA();

		//ptr->fun();

		//delete ptr;
	}
}