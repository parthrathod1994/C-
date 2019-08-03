#include<iostream>
using namespace std;
//high cohession 
//srp
//Dry -> pure fabrication
namespace nm01_1
{
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
	template<typename T>
	class Account
	{
		DB db;//smell
	protected:
		Account()
		{
		}
	public:
		void DoJob()
		{
			db.OpenDb();
			static_cast<T*>(this)->ActualJob();
			db.CloseDb();
			cout << "_____________________________\n";
		}

	};
	class SavingsAccount :public Account<SavingsAccount>
	{
	public:
		void ActualJob()
		{
			cout << "Withdraw for Current" << endl;
		}
	};
	class CurrentAccount :public Account<CurrentAccount>
	{
	public:
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