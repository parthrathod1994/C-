#include<iostream>
using namespace std;
namespace nm44
{
	class CA
	{
		int arr[3]{ 11,22,33 };
	public:
		int & operator[](int index)
		{
			return arr[index];
		}
		void Display()
		{
			for (int i = 0; i < 3; i++)
			{
				cout << "arr[" << i << "]=" << arr[i] << endl;
			}
			cout << "________________________________\n";
		}
	};

	void main()
	{
		CA obj;
		obj[1] = 888;//obj.operator[](1) = 999; //obj[1] = 999;
		obj.Display();
	}
}