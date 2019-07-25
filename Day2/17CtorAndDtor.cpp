#include<iostream>
using std::cout;
using std::endl;
namespace nm17
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor" << endl;
		}
		void fun()
		{
			cout << "CA fun" << endl;
		}
		~CA()
		{
			cout << "CA Dtor" << endl;
		}
	};

	void main1()
	{
		CA obj;
		/*
		lea	ecx, DWORD PTR _obj$[ebp]
		call	??0CA@@QAE@XZ				; CA::CA
		*/
		obj.fun();
		/*
		lea	ecx, DWORD PTR _obj$[ebp]
		call	?fun@CA@@QAEXXZ				; CA::fun
		*/
		cout << "______________________\n";
	}
	/*
		lea	ecx, DWORD PTR _obj$[ebp]
		call	??1CA@@QAE@XZ				; CA::~CA
	*/


	class CB :public CA
	{
	public:
		CB()//call	??0CA@@QAE@XZ				; CA::CA
		{
			cout << "CB Ctor" << endl;
		}

		~CB()
		{
			cout << "CB Dtor" << endl;
		}//call	??1CA@@QAE@XZ				; CA::~CA
	};

	void main()
	{
		CB obj;//call	??0CB@@QAE@XZ				; CB::CB
		obj.fun();
		cout << "______________________________________\n";
	}//	call	??1CB@@QAE@XZ				; CB::~CB
}