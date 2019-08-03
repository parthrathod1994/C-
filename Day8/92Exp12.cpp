#include<iostream>
using namespace std;
namespace nm92
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor\n";
		}
		~CA()
		{
			cout << "CA D-tor\n";
			throw 400;//never throw exceptions from Dtor(Exception overlap)
		}
	};

	void main()
	{
		try
		{
			try
			{
				CA obj;
				throw 100;
			}
			catch (int exp)
			{
				cout << "Inner int Exp=" << exp << endl;
			}

		}
		catch (int exp)
		{
			cout << "Outer int Exp=" << exp << endl;
		}


	}
}