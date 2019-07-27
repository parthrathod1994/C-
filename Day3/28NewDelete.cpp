#include<iostream>
using std::cout;
using std::endl;

namespace nm28
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA C-tor" << endl;
		}
		void fun()
		{
			cout << "CA::fun()" << endl;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
	};

	void main1()
	{
		//heap object
		CA *ptr = (CA*)malloc(sizeof(CA));
		ptr->fun();
		free(ptr);
	}

	void main2()
	{
		//heap object
		CA *ptr = (CA*)malloc(sizeof(CA));
		ptr->CA::CA();
		cout << "____________________\n";
		ptr->fun();
		cout << "____________________\n";
		ptr->CA::~CA();
		free(ptr);
	}

	void main3()
	{
		//heap object
		CA *ptr = new CA();
		cout << "____________________\n";
		ptr->fun();
		cout << "____________________\n";
		delete ptr;
	}


	void main4()
	{
		CA *ptr = new CA();
		/*
		CA* ptr=operator new(size){return malloc(size);}
		ptr->CA::CA();
		*/
		cout << "____________________\n";
		ptr->fun();
		cout << "____________________\n";
		delete ptr;
		/*
		ptr->CA::~CA();
		operator delete(ptr){free(ptr);};
		*/
	}


	class CB
	{
	public:
		static void* operator new(size_t size)
		{
			cout << "CB operator new \n";
			return malloc(size);
		}
		static void operator delete(void *pv)
		{
			cout << "CB operator delete \n";
			free(pv);
		}
		CB()
		{
			cout << "CB C-tor" << endl;
		}
		void fun()
		{
			cout << "CB::fun()" << endl;
		}
		~CB()
		{
			cout << "CB D-tor" << endl;
		}
	};


	void main()
	{
		CB *ptr = new CB();
		cout << "____________________\n";
		ptr->fun();
		cout << "____________________\n";
		delete ptr;
	}
}