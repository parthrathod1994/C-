#include<iostream>
using namespace std;

namespace nm07
{
	class Approver
	{
		Approver *sucessor = NULL;
	protected:
		void InformSuccessor(int loan_amount)//traversal
		{
			if (sucessor != NULL)
				sucessor->ProcessLoan(loan_amount);
		}
	public:
		virtual void ProcessLoan(int amount) = 0;
		void Set_Successor(Approver *sucessor)
		{
			this->sucessor = sucessor;
		}
		operator Approver*()
		{
			return this;
		}
	};
	class Cashier :public Approver
	{
	public:
		void ProcessLoan(int amount)
		{
			if (amount < 20000)
				cout << "Cahier processed loan of " << amount << endl;
			else
			{
				cout << "Cahier Cannot process loan of " << amount << endl;
				InformSuccessor(amount);

			}
		}
	};
	class Manager :public Approver
	{
	public:
		void ProcessLoan(int amount)
		{
			if (amount < 50000)
				cout << "Manager processed loan of " << amount << endl;
			else
			{
				cout << "Manager Cannot process loan of " << amount << endl;
				InformSuccessor(amount);

			}
		}
	};
	class Director :public Approver
	{
	public:
		void ProcessLoan(int amount)
		{
			if (amount < 70000)
				cout << "Director processed loan of " << amount << endl;
			else
			{
				cout << "Director Cannot process loan of " << amount << endl;
				InformSuccessor(amount);

			}
		}
	};
	void main()
	{
		Cashier cashier;
		Manager man;
		Director director;
		cashier.Set_Successor(man);
		man.Set_Successor(director);

		cashier.ProcessLoan(75000);
	}
}