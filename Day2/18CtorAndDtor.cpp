#include<iostream>
using std::cout;
using std::endl;
namespace nm18
{
	class Limb
	{
	public:
		Limb()
		{
			cout << "Limb C-tor" << endl;
		}
		~Limb()
		{
			cout << "Limb D-tor" << endl;
		}
	};

	class Tiger
	{
		Limb limb;
	public:
		Tiger()//limb::limb()
		{
			cout << "Tiger C-tor" << endl;
		}
		~Tiger()
		{
			cout << "Tiger D-tor" << endl;
		}//limb::~limb()
	};

	void main1()
	{
		Tiger tiger;//tiger::tiger

	}//tiger::~tiger()


	class Animal
	{
	public:
		Animal()
		{
			cout << "Animal C-tor" << endl;
		}
		~Animal()
		{
			cout << "Animal D-tor" << endl;
		}
	};

	class Vertibrate
	{
	public:
		Vertibrate()
		{
			cout << "Vertibrate C-tor" << endl;
		}
		~Vertibrate()
		{
			cout << "Vertibrate D-tor" << endl;
		}
	};

	class Eye
	{
	public:
		Eye()
		{
			cout << "Eye C-tor" << endl;
		}
		~Eye()
		{
			cout << "Eye D-tor" << endl;
		}
	};

	class Cat :public Animal, public Vertibrate
	{
		Limb limb;
		Eye eye;
	public:
		Cat()
			//Animal::Animal 
			//Limb::Limb()
		{
			cout << "Cat C-tor" << endl;
		}

		~Cat()
		{
			cout << "Cat D-tor" << endl;
		}
		/*
		Limb::~Limb()
		Animal::~Animal();
		*/
	};

	void main()
	{
		Cat cat;//CA::CAT();
	}//CAT::~CAT()
}