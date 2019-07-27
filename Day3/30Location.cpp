#include<iostream>
using std::cout;
using std::endl;
namespace nm30
{
	class CA
	{
		bool is_on_heap;
		static int count;
	public:
		CA() :is_on_heap(true)
		{
			count--;
			if (count < 0)
				is_on_heap = false;
			cout << "CA Default Ctor\n";

		}
		static void* operator new(size_t size)
		{
			count = 1;
			cout << "CA operator (new) \n";

			return malloc(size);;
		}
		static void* operator new[](size_t size)
		{

			cout << "CA operator (new[]) \n";
			count = size / sizeof(CA) - 4;
			cout << "count=" << count << endl;

			return malloc(size);;
		}
			void Location()
		{
			if (is_on_heap == true)
			{
				cout << "I am on heap\n";
			}
			else if (is_on_heap == false)
			{
				cout << "I am (NOT) on heap\n";
			}
		}
		~CA()
		{
			cout << "CA Dtor" << endl;
		}
	};
	int CA::count = 0;

	void main()
	{
		CA *ptr1 = new CA();
		cout << "************************************\n";
		CA *ptr3 = new CA[5];
		long* pt = (long*)ptr3;
		cout << "size=" << *(pt - 1) << endl;
		cout << "************************************\n";
		CA obj1;
		CA *ptr2 = new CA();
		CA obj2;
		cout << "____________________________________\n";
		obj1.Location();
		obj2.Location();
		cout << "____________________________________\n";
		ptr1->Location();
		ptr2->Location();
		cout << "____________________________________\n";
		for (int i = 0; i < 5; i++)
		{
			(ptr3 + i)->Location();

		}
		cout << "____________________________________\n";
		delete ptr1;
		delete ptr2;
		cout << "____________________________________\n";
		cout << "************************************\n";
		delete[] ptr3;
		cout << "************************************\n";
	}
}