#include<iostream>

using namespace std;

namespace nm51Parth
{
	class CA
	{
		int *i;
		int *count;
	public:
		CA() :i(new int(10)), count(new int(1))
		{

			cout << "CA Ctor called with i holding " << i << endl;
		}
		CA(const CA& par) :i(par.i), count(par.count)
		{
			++(*count);
		}
		void fun()
		{
			cout << "fun called with i holding " << i << endl;
		}
		CA& operator=(CA par)
		{
			swap(this->i, par.i);
			swap(this->count, par.count);
			return *this;
		}

		~CA()
		{
			--(*count);
			if ((*count) == 0)
			{
				cout << "CA D-tor called with i released " << i << endl;
				delete i;
				delete count;
			}

		}
	};


	void main()
	{
		CA obj1;
		CA obj2(obj1);
		CA obj3(obj2);

		CA obj4;
		CA obj5(obj4);

		CA obj6;
		cout << "_____________________________________\n";
	}
}