#include<iostream>
using  std::cout;
using  std::endl;
namespace nm45
{
	template<int size>
	class CA
	{
		int arr[size];
	public:
		CA()
		{
			cout << "CA Default" << endl;
		}
		//Init Ctors from modern c++
		CA(std::initializer_list<int> list)
		{

			int count = 0;
			std::initializer_list<int>::iterator itStart = list.begin();
			std::initializer_list<int>::iterator itEnd = list.end();
			while (itStart != itEnd)
			{
				arr[count++] = *itStart;
				++itStart;
			}


			cout << "Init Ctors" << endl;
		}
		int & operator[](int index)
		{
			return arr[index];
		}
		void Display()
		{
			for (int i = 0; i < size; i++)
			{
				cout << "arr[" << i << "]=" << arr[i] << endl;
			}
			cout << "________________________________\n";
		}
	};

	void main()
	{
		CA<5> obj{ 11,22,33,44,55,66 };
		obj[1] = 888;
		obj.Display();
	}
}