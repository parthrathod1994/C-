#include<iostream>
#include<map>
using namespace std;


namespace nm50AtulJi
{

	class CA
	{
		int *i;
		static map<int*, int> repo;
	public:
		CA() :i(new int(10))
		{
			repo[i] = 1;
			cout << "CA Ctor called with i holding " << i << endl;
		}
		CA(const CA& par) :i(par.i)
		{
			repo[i]++;
		}
		void fun()
		{
			cout << "fun called with i holding " << i << endl;
		}
		CA& operator=(CA par)
		{
			swap(this->i, par.i);
			return *this;
		}
		~CA()
		{
			repo[i]--;
			if (repo[i] == 0)
			{
				cout << "CA D-tor called with i released " << i << endl;
				delete i;
				repo.erase(i);
			}
		}
	};
	map<int*, int> CA::repo;

	void main()
	{
		CA obj1;
		CA obj2(obj1);
		CA obj3(obj2);

		CA obj4;
		CA obj5(obj4);

		CA obj6;
		obj1 = obj6;
		cout << "_____________________________________\n";
	}
}