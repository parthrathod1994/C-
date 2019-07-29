#include<iostream>
using namespace std;
namespace nm42
{
	class CA
	{
		int x = 10;
		int y = 20;
	public:
		explicit operator int()//casting operators with explicit from modern c++
		{
			cout << "CA::casting called \n";
			return x + y;
		}
	};

	void main()
	{
		CA obj;
		//int res = obj.operator int();
		int res1 = (int)obj;
		//int res2 = obj;

		cout << "res=" << res1 << endl;
	}
}