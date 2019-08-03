#include<iostream>
using namespace std;
namespace nm93
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor\n";
			throw 100;
		}
		static void*operator new(size_t size)
		{
			cout << "CA::operator new " << endl;
			return  ::operator new(size);
		}
		static void operator delete(void *pv)
		{
			cout << "CA::operator delete " << endl;
			free(pv);
		}
		~CA()
		{
			cout << "CA D-tor\n";
		}
	};

	void main()
	{
		CA *obj = NULL;
		try
		{
			obj = new CA();
			/*
				CA* temp= operator new(1);
				try
				{
					temp->CA::CA();
				}
				catch(...)
				{
					operator delete(temp);
					throw;
				}
				obj=temp;
			*/
		}
		catch (int exp)
		{
			cout << "int exp=" << exp << endl;
		}
		catch (bad_alloc & exp)
		{
			cout << "Memory not alloted" << endl;
		}

		if (obj == NULL)
		{
			cout << "Apple" << endl;
		}
		else
		{
			cout << "Orange " << endl;
			delete obj;
		}
	}
}