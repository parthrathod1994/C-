#include<iostream>
using namespace std;
namespace nm03
{
	class DB
	{
	public:
		virtual void OpenDb() = 0;
		virtual void CloseDb() = 0;
	};
	class NullDb :public DB {
	public:
		virtual void OpenDb()
		{
			//do nothing
		}
		virtual void CloseDb()
		{
			//do nothing
		}
	};
	class SqlDb :public DB {
	public:
		virtual void OpenDb()
		{
			cout << "open SQL DB" << endl;
		}
		virtual void CloseDb()
		{
			cout << "close SQL DB" << endl;
		}
	};
	class OraDb :public DB {
	public:
		virtual void OpenDb()
		{
			cout << "open ORA DB" << endl;
		}
		virtual void CloseDb()
		{
			cout << "close ORA DB" << endl;
		}
	};
	class Account
	{
		DB *db = new NullDb();//smell
	protected:
		Account()
		{
		}
		virtual void ActualJob() = 0;
	public:
		void SetDb(DB *db)
		{
			delete this->db;
			this->db = db;
		}
		void DoJob()
		{
			db->OpenDb();
			ActualJob();
			db->CloseDb();
			cout << "_____________________________\n";
		}
		~Account()
		{
			delete db;
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
	class DbNew
	{
	public:
		virtual void Connect() = 0;
		virtual void Disconnect() = 0;
	};
	class Db2 :public DbNew
	{
	public:
		void Connect()
		{
			cout << "DB2 connected " << endl;
		}
		void Disconnect()
		{
			cout << "DB2 disconnected " << endl;
		}
	};


	class DbNewAdapter :public DB
	{
		DbNew *pt;
	public:
		DbNewAdapter(DbNew *pt) :pt(pt)
		{
		}
		virtual void OpenDb()
		{
			pt->Connect();
		}
		virtual void CloseDb()
		{
			pt->Disconnect();
		}
	};

	void main()
	{
		SavingsAccount sa;
		sa.SetDb(new SqlDb());
		sa.DoJob();

		CurrentAccount curr;
		curr.SetDb(new DbNewAdapter(new Db2()));
		curr.DoJob();
	}
}