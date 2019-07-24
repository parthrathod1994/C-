//#include<iostream>
//using namespace std;
//object -> state + behavior
namespace nm08
{
	class CA//class
	{
	public:
		//state (data members)
		int x;
		int y;

		//behavior
		void Display()
		{//_this$ = ecx
			//cout << "_________________" << this << "_______________\n";
			/*cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "_____________________________\n";*/
		}
	};

	void main()
	{
		CA obj1;//object
		CA obj2;
		obj1.x = 100;
		obj1.y = 200;
		obj2.x = 300;
		obj2.y = 400;
	/*	cout << "&obj1=" << &obj1 << endl;
		cout << "&obj2=" << &obj2 << endl;*/
		obj1.Display();
		/*
			lea	ecx, DWORD PTR _obj1$[ebp]
			call	?Display@CA@@QAEXXZ			; CA::Display
		*/
		obj2.Display();
	}
}