#include<iostream>
using std::cout;
using std::endl;
namespace nm29
{
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
			//delete this;
			/*
		call CB::~CB();
		CB::operator delete(this);
		*/
		}
	};

	void main()
	{
		CB *ptr = new CB();
		/*
		call	??2CB@@SAPAXI@Z				; CB::operator new
		call	??0CB@@QAE@XZ				; CB::CB

		*/
		cout << "____________________\n";
		ptr->fun();
		cout << "____________________\n";
		delete ptr;
		/*
		call CB::~CB();
		CB::operator delete(ptr);
		*/
	}
}