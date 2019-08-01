#include<iostream>
#include<string>
using namespace std;

namespace nm79
{
	class CA
	{
	public:
		int x = 100;
	};
	class CB :public CA
	{
	public:
		int y = 200;
	};
	class CC :public CA
	{
	public:
		int c = 300;
	};
	class CD :public CB, public CC
	{
	public:
		int a = 400;
	};

	void main()
	{
		CD obj;
		obj.CB::x = 999;
		obj.CC::x = 666;
		//cout << sizeof(obj) << endl;
		long* ptr = (long*)&obj;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;
		ptr++;
		cout << *ptr << endl;

	}
}