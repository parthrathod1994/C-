#include<iostream>
using namespace std;
void * operator new(size_t size, const char *ch)
{
	cout << "Gloabal new(char*)" << endl;
	return malloc(size);
}
namespace nm97
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor created at " << this << endl;
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

	void main1()
	{
		CA *ptr = NULL;
		try
		{
			ptr = new CA();//normal new
			ptr->fun();
			delete ptr;
		}
		catch (bad_alloc & exp)
		{
			cout << exp.what() << endl;
		}

	}

	void main2()
	{
		CA *ptr = new(nothrow) CA();//nothrow new
		if (ptr != NULL)
		{
			ptr->fun();
			delete ptr;
			ptr = NULL;
		}
	}


	void main3()
	{
		int *buffer = new int[10000];
		cout << "buffer=" << buffer << endl;

		CA* ptr = new(buffer) CA();//placement new
		CA* ptr1 = new(buffer + 1) CA();

		//delete ptr; //should not do this
		//delete ptr1;//cannot do this not the base address
		//Destructors for placement new has to be called explicitly
		ptr->CA::~CA();
		ptr1->CA::~CA();
		delete[] buffer;
	}



	class CB
	{
	public:
		CB()
		{
			cout << "CA Ctor created at " << this << endl;
		}
		void fun()
		{
			cout << "CA Fun" << endl;
		}
		static void* operator new(size_t size)
		{
			cout << "CA::operator new " << endl;
			return malloc(size);
		}
		static void* operator new(size_t size, int x, int y, int z)
		{
			cout << "CA::operator new(int,int) " << endl;
			return malloc(size);
		}
		~CB()
		{
			cout << "CA D-tor" << endl;
		}
	};

	

	void main()
	{
		CB *ptr = new CB();
		CB *ptr1 = new(1, 2, 3) CB();

		delete ptr;
		delete ptr1;

		int *i = new int(100);
		int *i1 = new("sachin") int(200);
	}
}