#include<iostream>
using namespace std;
namespace nm01
{
	//high cohession 
	//srp
	//Dry -> pure fabrication
	class DB
	{
	public:
		void OpenDb()
		{
			cout << "open DB" << endl;
		}
		void CloseDb()
		{
			cout << "close DB" << endl;
		}
	};
	class Account
	{
		DB db;
	protected:
		Account()
		{
		}
		virtual void ActualJob() = 0;
	public:
		void DoJob()
		{
			db.OpenDb();
			ActualJob();
			db.CloseDb();
			cout << "_____________________________\n";
		}
	};
	class SavingsAccount :public Account
	{
	protected:
		void ActualJob()
		{
			cout << "Withdraw for Current" << endl;
		}
	};
	class CurrentAccount :public Account
	{
	protected:
		void ActualJob()
		{
			cout << "Withdraw for Savings" << endl;
		}
	};

	//-----------

	//consumer

	void main()
	{
		SavingsAccount sa;
		sa.DoJob();

		CurrentAccount curr;
		curr.DoJob();
	}
}