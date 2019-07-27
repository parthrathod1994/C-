#include<iostream>
using std::cout;
using std::endl;
namespace nm27
{
	class Employee
	{
	public:
		void InitJob(/*recive */)
		{
			cout << "Init Job Employee" << endl;
		}
		virtual void DoJob()
		{
			cout << "Employee Job Done" << endl;
		}
	};

	void DoBusiness(Employee *emp)//LSP
	{
		cout << "______________________________\n";
		cout << "Vendor Business Started   " << endl;
		emp->DoJob();
		cout << "Vendor Business Completed " << endl;
		cout << "______________________________\n";
	}

	//---------------------------Vendor Code Ends------------------


	void  main1()
	{
		Employee emp;
		emp.InitJob();
		DoBusiness(&emp);
	}
	class Manager :public Employee
	{
	public:
		void DoJob() override //c++11 onwards
		{
			cout << "Manager Job Done" << endl;
		}
	};
	class Developer :public Employee
	{
	public:
		void DoJob() override //c++11 onwards
		{
			cout << "Developer Job Done" << endl;
		}
	};

	class Tester :public Employee
	{
	public:
		void DoJob() override //c++11 onwards
		{
			cout << "Tester Job Done" << endl;
		}
	};
	void main()
	{
		Manager man;
		Developer dev;
		Tester test;
		man.InitJob();
		dev.InitJob();
		test.InitJob();
		DoBusiness(&man);
		DoBusiness(&dev);
		DoBusiness(&test);
	}
}