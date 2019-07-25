#include<iostream>
using std::cout;
using std::endl;

namespace nm22
{
	class CA
	{
	public:
		CA()
		{
			fun();//this->fun()
		}
		virtual void fun()
		{
			cout << "CA fun" << endl;
		}
		void MyFun()
		{
			fun();//this->fun();
		}
		~CA()
		{
			fun();//this->fun();
		}
	};
	class CB :public CA
	{
	public:
		CB()
		{
			fun();//this->fun();
		}
		virtual void fun()
		{
			cout << "CB fun" << endl;
		}
		~CB()
		{
			fun();//this->fun();
		}
	};

	void main1()
	{
		CB obj;
		obj.MyFun();
	}

	void main()
	{
		CB obj;
		obj.MyFun();
		cout << "_______________________________\n";
		obj.CA::CA();
		obj.MyFun();
		cout << "_______________________________\n";
	}
}