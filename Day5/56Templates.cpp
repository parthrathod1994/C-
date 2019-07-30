#include<iostream>
using namespace std;
namespace nm56
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor\n";
		}
		void fun()
		{
			cout << "\t\tCA fun\n";
		}
		~CA()
		{
			cout << "CA D-tor\n";
		}
	};

	class CB
	{
	public:
		CB()
		{
			cout << "CB Ctor\n";
		}
		void Apple()
		{
			cout << "\t\tCB Apple Fun\n";
		}
		~CB()
		{
			cout << "CB D-tor\n";
		}
	};

	template<typename T>
	class Smart
	{
		T* ptr;
	public:
		Smart() :ptr(new T())
		{
		}
		T* operator->()
		{
			return ptr;
		}
		~Smart()
		{
			delete ptr;
		}
	};

	void main()
	{
		Smart<CA> ptr1;
		Smart<CB> ptr2;
		ptr1->fun();
		ptr2->Apple();
	}
}