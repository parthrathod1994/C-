#include<iostream>
using namespace std;
namespace nm09
{
	class CA
	{
	public:
		int x = 10;//member initialization from (modern) c++11 onwards
		int y = 20;
		void Display()//can change the object state (Mutators)
		{
			x += 100;
			y = 999;
			cout << "_________________" << this << "_______________\n";
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "_____________________________\n";
		}
		void DisplayNew() const//does not  change the object state (Inspectors)
		{
			//x += 100;//error bescause of inspector
			//y = 999;
			cout << "_________________" << this << "_______________\n";
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "_____________________________\n";
		}
	};

	void main()
	{
		CA obj1;
		const CA obj2;
		obj1.x = 888;
		//obj2.x = 999;//error
		obj1.Display();
		//obj2.Display();//const objects can call only inspectors
		obj2.DisplayNew();
	}
}