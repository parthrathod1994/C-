#include<iostream>
using namespace std;
namespace nm43
{
	class CA
	{
		int x = 10;
		int y = 20;
	public:
		/*explicit*/ CA(int par)
		{
			cout << "CA One Param\n";
			cout << "&x=" << &x << endl;
			cout << "&y=" << &y << endl;
			cout << "___________________________\n";
		}
		CA(const CA& par)
		{
			cout << "CA Copy \n";
		}
		CA& operator=(const CA& par)
		{
			cout << "CA Assign \n";
			return *this;
		}
		operator void*()
		{
			return this;
		}
	};




	void main1()
	{
		CA obj1 = 10;//casting
		CA obj2(200);//construction
		obj1 = 400;//assignment
		CA obj3{ 100 };//construction
		CA obj4 = { 400 };//casting
		obj4 = { 111 };
		cout << "__________________________" << endl;
		CA obj5(obj2);
		CA obj6 = obj2;
		CA obj7{ obj2 };
		CA obj8 = { obj2 };
		cout << "__________________________" << endl;
		obj2 = obj5;
		cout << "__________________________" << endl;
		void *ptr = obj5.operator void*();
		//void *ptr = obj5;
		cout << "ptr=" << ptr << endl;
		cout << "&obj5=" << &obj5 << endl;
	}


	class CB
	{
		int x = 10;
		int y = 20;
	public:
		CB()
		{
			cout << "___________________________\n";
			cout << "&x=" << &x << endl;
			cout << "&y=" << &y << endl;
			cout << "___________________________\n";
		}
		void* operator&()
		{
			return &y;
		}
	};
	void main()
	{
		CB obj1;
		cout << "&obj1=" << &obj1 << endl;
		cout << "addressofobj1=" << addressof(obj1) << endl;
	}
}