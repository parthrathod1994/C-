#include<iostream>
using std::cout;
using std::endl;

namespace nm16
{
	class CA
	{
	public:
		void fun1()
		{
			cout << "Apple" << endl;
		}
		void fun2()
		{
			cout << "Orange" << endl;
		}
	};

	class CB :public CA
	{
	public:
		void fun3()
		{
			cout << "Banana" << endl;
		}
		void fun2() //function hiding
		{
			cout << "Jack" << endl;
		}
	};

	void main1()
	{
		CA obj;
		CB obj1;
		obj.fun1();//apple //CA::fun1 //call	?fun1@CA@@QAEXXZ			; CA::fun1
		obj.fun2();//orange //CA::fun2 //	call	?fun2@CA@@QAEXXZ			; CA::fun2
		cout << "__________________________\n";
		obj1.fun1();//apple //CA::fun1 //call	?fun1@CA@@QAEXXZ			; CA::fun1
		obj1.fun2();//jack /orange  //CB::fun2 //call	?fun2@CB@@QAEXXZ			; CB::fun2
		obj1.fun3();//banana //CB::fun3 // call	?fun3@CB@@QAEXXZ			; CB::fun3
		obj1.CA::fun2();//	call	?fun2@CA@@QAEXXZ			; CA::fun2
		cout << "__________________________\n";
		/*

		*/
	}





	class CMath
	{
	public:
		void AddFun(int x)
		{
			cout << "CMath::Addfun(int)" << endl;
		}
		void AddFun(int x, int y)
		{
			cout << "CMath::Addfun(int,int)" << endl;
		}
	};
	class CMathEx :public CMath
	{
	public:
		using CMath::AddFun;
		/*void AddFun(int x, int y)
		{
			cout << "CMathEx::Addfun(int,int)" << endl;
		}*/
		void AddFun(int x, int y, int z)
		{
			cout << "CMathEx::Addfun(int,int,int)" << endl;
		}
	};

	void main()
	{
		CMathEx obj;
		//obj.CMath::AddFun(10);
		//obj.CMath::AddFun(111, 222);
		obj.AddFun(10);
		obj.AddFun(1, 2);
		obj.AddFun(1, 2, 3);
	}
}