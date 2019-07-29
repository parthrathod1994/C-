namespace nm33
{
	//constructors
	class CA
	{
	public:
		CA()
		{
		}
		void fun()
		{
		}
	};
	class CB :public CA
	{
	public:
		/*CB()
		{
		}*/
	};

	class CAT
	{
	public:
		CAT()
		{

		}
	};
	class Kettle
	{
		CAT cat;
	public:
		/*Kettle()
		{

		}*/
		void Store()
		{

		}
	};


	class Employee
	{
	public:
		virtual void fun()
		{

		}
	};

	void main()
	{
		Employee emp;
		emp.fun();
	}

	void main2()
	{
		Kettle kettle;
		kettle.Store();
	}
	void  main1()
	{
		CB obj;
		obj.fun();
	}
}