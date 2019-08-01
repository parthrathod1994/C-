#include<iostream>
#include<string>
using namespace std;


	
	//--------------------------------------------------
namespace nm89
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor" << endl;
		}
		CA(const CA& par)
		{
			cout << "CA Copy" << endl;
		}
		~CA()
		{
			cout << "CA D-tor" << endl;
		}
	};

	void main()
	{
		int x = 10;
		cout << "Mango" << endl;
		try
		{
			CA obj;
			if (10 == x)
				throw obj;
		}
		catch (int exp)
		{
			cout << "exp " << exp << endl;
		}
		catch (CA exp)
		{
			cout << "CA exp " << endl;
		}
		cout << "Jack" << endl;
	}
}