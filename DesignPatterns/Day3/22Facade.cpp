#include<iostream>
#include<string>
#include<vector>
using namespace std;
namespace nm22
{
	class Account
	{
		int amount;
	public:
		Account(int amount) :amount(amount)
		{
		}
		void Withdraw(int amount)
		{
			this->amount -= amount;
		}
	};
	class Informers
	{
	public:
		virtual void Send(int amount) = 0;
	};
	class RBI :public Informers
	{
	public:
		void Send(int amount)
		{
			cout << "RBI Recieved the amount info" << endl;
		}
	};

	class IncomeTax :public Informers
	{
	public:
		void Send(int amount)
		{
			cout << "IncomeTax Recieved the amount info" << endl;
		}
	};
	class ServiceTax :public Informers
	{
	public:
		void Send(int amount)
		{
			cout << "ServiceTax Recieved the amount info " << endl;
		}
	};

	class TransactionHelper
	{
		Account & acc;
		vector<Informers*> info_pass;
	public:
		TransactionHelper(Account & acc) :acc(acc)
		{
			info_pass.push_back(new RBI());
			info_pass.push_back(new IncomeTax());
			info_pass.push_back(new ServiceTax());
		}
		void Withdraw(int amount)
		{
			cout << "Logging the info" << endl;
			acc.Withdraw(amount);
			for (int i = 0; i < info_pass.size(); i++)
			{
				info_pass.at(i)->Send(amount);
			}
		}
	};

	void main()
	{
		Account acc(10000);
		TransactionHelper trans(acc);
		trans.Withdraw(4000);
	}
}