#include<iostream>
using namespace std;
namespace nm04
{
	class Account;
	class SavingsAccount;
	class CurrentAccount;
	class DmatAccount;

	class ITransInfo
	{
	public:
		virtual void SendInfo(Account*) = 0;
		virtual void SendInfo(SavingsAccount*) = 0;
		virtual void SendInfo(CurrentAccount*) = 0;
		virtual void SendInfo(DmatAccount*) = 0;
	};

	class NullTrans :public ITransInfo
	{
	public:
		virtual void SendInfo(Account*) {}
		virtual void SendInfo(SavingsAccount*) {}
		virtual void SendInfo(CurrentAccount*) {}
		virtual void SendInfo(DmatAccount*) {}
	};

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
		static ITransInfo *info;
		Account()
		{
		}
		virtual void ActualJob() = 0;
	public:
		static void SetTransInfo(ITransInfo *infoPar)
		{
			delete info;
			info = infoPar;
		}
		void DoJob()
		{
			db.OpenDb();
			ActualJob();
			db.CloseDb();
			cout << "_____________________________\n";
		}
	};
	ITransInfo * Account::info = new NullTrans();

	class SavingsAccount :public Account
	{
	protected:
		void ActualJob()
		{
			cout << "Withdraw for savings" << endl;
			info->SendInfo(this); //TransInfo
		}
	};
	class CurrentAccount :public Account
	{
	protected:
		void ActualJob()
		{
			cout << "Withdraw for current" << endl;
			info->SendInfo(this); //TransInfo
		}
	};
	class DmatAccount :public Account
	{
	protected:
		void ActualJob()
		{
			cout << "Withdraw for Dmat" << endl;
			info->SendInfo(this); //TransInfo
		}
	};
	//-----------

	//consumer

	class DeewaliTrans :public ITransInfo
	{
	public:
		virtual void SendInfo(Account*) {
			cout << "Deewali transaction info  (General)" << endl;
		}
		virtual void SendInfo(SavingsAccount*) {
			cout << "Deewali (SAVINGS) transaction info " << endl;
		}
		virtual void SendInfo(CurrentAccount*) {
			cout << "Deewali (Current) transaction info " << endl;
		}
		virtual void SendInfo(DmatAccount*) {
			cout << "Deewali (DMat) transaction info " << endl;
		}
	};
	class ChristmasTrans :public ITransInfo
	{
	public:
		virtual void SendInfo(Account*) {
			cout << "Christmas transaction info (General) " << endl;
		}
		virtual void SendInfo(SavingsAccount*) {
			cout << "Christmas (SAVINGS) transaction info " << endl;
		}
		virtual void SendInfo(CurrentAccount*) {
			cout << "Christmas (Current) transaction info " << endl;
		}
		virtual void SendInfo(DmatAccount*) {
			cout << "Christmas (DMat) transaction info " << endl;
		}
	};

	class ChildAccount :public Account
	{
	protected:
		void ActualJob()
		{
			cout << "Withdraw for Child " << endl;
			info->SendInfo(this); //TransInfo
		}
	};

	void main()
	{
		Account::SetTransInfo(new ChristmasTrans());
		SavingsAccount sa;
		sa.DoJob();

		CurrentAccount curr;
		curr.DoJob();

		DmatAccount dmat;
		dmat.DoJob();

		ChildAccount child;
		child.DoJob();
	}
}