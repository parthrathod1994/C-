#include<iostream>
#include<string>
using namespace std;
namespace nm17
{

	class IIterator
	{
	public:
		virtual void First() = 0;
		virtual void Last() = 0;
		virtual bool Next() = 0;
		virtual int Current() = 0;
		virtual void MoveNext() = 0;
	};

	class Container
	{
		int arr[5];
		int size = 5;
	public:
		Container() :arr{ 11,22,33,44,55 }
		{
		}
		Container *begin()
		{
			return this;
		}
		class iterator :public IIterator
		{
			Container *container;
			int size;
			int nav = 0;
		public:
			iterator(Container *container) :container(container), size(container->size)
			{
				First();
			}
			virtual void First()
			{
				nav = 0;
			}
			virtual void Last()
			{
				nav = size - 1;

			}
			virtual bool Next()
			{
				return nav < size;
			}
			void MoveNext()
			{
				nav++;
			}
			virtual int Current()
			{
				return container->arr[nav];
			}
			int operator*()
			{
				return Current();
			}
			void operator++()
			{
				MoveNext();
			}
			void operator++(int)
			{
				MoveNext();
			}
		};


	};


	void main()
	{
		Container contaner;

		Container::iterator it = contaner.begin();
		while (it.Next())
		{
			//cout << it.Current() << endl;
			//it.MoveNext();
			cout << *it << endl;
			++it;

		}
	}
}