#include<iostream>
using namespace std;
	
namespace nm91
{
	void main()
	{
		try
		{
			try
			{
				//throw 100;
				throw 3.14159;
			}
			catch (int exp)
			{
				exp += 100;
				cout << "Inner int Exp=" << exp << endl;
				throw;//rethrow
			}
			catch (...)//catch any / catch all / general exception
			{
				cout << "General Exception\n";
				throw;
			}
		}
		catch (int exp)
		{
			cout << "Outer int Exp=" << exp << endl;
		}
		catch (double exp)
		{
			cout << "Outer double Exp=" << exp << endl;
		}
	}
}
	