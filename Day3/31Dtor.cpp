#include<iostream>
using std::cout;
using std::endl;

class CA
{
public:
	CA()
	{
		cout << "CA C-tor\n";
	}
	virtual ~CA()
	{
		cout << "CA D-tor\n";
	}
};
class CB:public CA
{
public:
	CB()
	{
		cout << "CB C-tor\n";
	}
	~CB()
	{
		cout << "CB D-tor\n";
	}
};

void main1()
{
	delete new CB();
}

void main2()
{
	CB *ptr = new CB();

	delete ptr;
}

void main()
{
	CA *ptr = new CB();

	delete ptr;
}