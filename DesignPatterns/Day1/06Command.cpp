#include<iostream>
#include<stack>
using namespace std;
namespace nm06
{
	class Account
	{
		int acct_id;
		int amount;
	public:
		Account(int acc_id, int amount) :acct_id(acct_id), amount(amount)
		{
		}
		void Withrawal(int amt)
		{
			amount -= amt;
		}
		void Deposit(int amt)
		{
			amount += amt;
		}
		int GetBalance()
		{
			return amount;
		}
	};

	class Command
	{
	protected:
		int tranAmount;
		Command(int tranAmount) :tranAmount(tranAmount)
		{
		}
	public:
		virtual void Execute(Account &acc) = 0;
		virtual void UnExecute(Account &acc) = 0;
	};
	class WithdrawCommand :public Command
	{
	public:
		WithdrawCommand(int tranAmount) :Command(tranAmount)
		{
		}
		virtual void Execute(Account &acc)
		{
			acc.Withrawal(tranAmount);
		}
		virtual void UnExecute(Account &acc)
		{
			acc.Deposit(tranAmount);
		}
	};
	class DepositCommand :public Command
	{
	public:
		DepositCommand(int tranAmount) :Command(tranAmount)
		{
		}
		virtual void Execute(Account &acc)
		{
			acc.Deposit(tranAmount);
		}
		virtual void UnExecute(Account &acc)
		{
			acc.Withrawal(tranAmount);
		}
	};

	class CommandRepository
	{
		stack<Command*> repo;
	public:
		void AddCommand(Command *cmd)
		{
			repo.push(cmd);
		}
		Command* UseLastCommand()
		{
			Command* temp = repo.top();
			repo.pop();

			return temp;
		}
	};

	class TransactionHelper
	{
		Account & acc;
		CommandRepository *repository;
	public:
		TransactionHelper(Account & acc) :acc(acc), repository(new CommandRepository())
		{
		}
		void Deposit(int amount)
		{
			Command *cmd = new DepositCommand(amount);
			cmd->Execute(acc);
			repository->AddCommand(cmd);
		}
		void Withraw(int amount)
		{
			Command *cmd = new WithdrawCommand(amount);
			cmd->Execute(acc);
			repository->AddCommand(cmd);
		}
		void Undo()
		{
			Command *cmd = repository->UseLastCommand();
			cmd->UnExecute(acc);
		}
		int Balance()
		{
			return acc.GetBalance();
		}
	};

	void main()
	{
		Account acc(101, 5000);
		TransactionHelper helper(acc);
		helper.Withraw(1000);
		helper.Withraw(500);
		helper.Deposit(2000);
		helper.Withraw(500);
		helper.Deposit(700);
		helper.Undo();
		helper.Undo();
		helper.Undo();
		cout << acc.GetBalance() << endl;
	}
}