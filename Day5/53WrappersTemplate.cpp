#include<iostream>
using namespace std;
namespace nm53
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

	template<typename T>
	class Wrapper
	{
		T* ptr;
	public:
		Wrapper() :ptr(new T())
		{
		}
		Wrapper(T* ptr) :ptr(ptr)
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
		T* operator->()
		{
			return ptr;
		}
		~Wrapper()
		{
			delete ptr;
		}
	};
	template<typename T>
	Wrapper<T> Make_Wraper()
	{
		//initial jobs
		return Wrapper<T>(new T());
	}


	void main1()
	{
		Wrapper<CA> w1 = Make_Wraper<CA>();
		w1->fun();//w1.operator->()->fun();

	}

	void main2()
	{
		unique_ptr<CA> w1 = make_unique<CA>();
		w1->fun();
		unique_ptr<CA> w2(new CA());

	}

	void main()
	{

		shared_ptr<CA> s1 = make_shared<CA>();
		shared_ptr<CA> s2 = s1;
		shared_ptr<CA> s3 = s2;
		shared_ptr<CA> s4 = make_shared<CA>();
		s1->fun();

	}


}