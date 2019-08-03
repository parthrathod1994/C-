#include<iostream>
using namespace std;
namespace nm05
{
	class Adapter
	{
	public:
		virtual void CreateAdapter() = 0;
		virtual void AttachAdapter() = 0;

	};
	class Command
	{
	public:
		virtual void CreateCommand() = 0;
		virtual void AttachCommand() = 0;
	};

	class Connection
	{
	public:
		virtual void CreateConnection() = 0;
		virtual void AttachConnection() = 0;
	};

	class Factory
	{
	public:
		virtual Adapter* BuildAdapter() = 0;
		virtual Connection* BuildConnection() = 0;
		virtual Command* BuildCommand() = 0;
	};

	class SqlAdapter :public Adapter
	{
	public:
		void CreateAdapter()
		{
			cout << "Sql Adapter Created" << endl;
		}
		void AttachAdapter()
		{
			cout << "Sql Adapter Attached" << endl;
		}
	};

	class SqlCommand :public Command
	{
	public:
		virtual void CreateCommand()
		{
			cout << "Sql Command Created" << endl;
		}
		virtual void AttachCommand()
		{
			cout << "Sql Command Attached" << endl;
		}
	};

	class SqlConnection :public Connection
	{
	public:
		virtual void CreateConnection()
		{
			cout << "Sql Connection Created" << endl;
		}
		virtual void AttachConnection()
		{
			cout << "Sql Connection Attached" << endl;
		}
	};

	class SqlFactory :public Factory
	{
	public:
		virtual Adapter* BuildAdapter()
		{
			return new SqlAdapter();
		}
		virtual Connection* BuildConnection()
		{
			return new SqlConnection();
		}
		virtual Command* BuildCommand()
		{
			return new SqlCommand();
		}
	};

	class OraAdapter :public Adapter
	{
	public:
		void CreateAdapter()
		{
			cout << "Ora Adapter Created" << endl;
		}
		void AttachAdapter()
		{
			cout << "Ora Adapter Attached" << endl;
		}
	};

	class OraCommand :public Command
	{
	public:
		virtual void CreateCommand()
		{
			cout << "Ora Command Created" << endl;
		}
		virtual void AttachCommand()
		{
			cout << "Ora Command Attached" << endl;
		}
	};

	class OraConnection :public Connection
	{
	public:
		virtual void CreateConnection()
		{
			cout << "Ora Connection Created" << endl;
		}
		virtual void AttachConnection()
		{
			cout << "Ora Connection Attached" << endl;
		}
	};

	class OraFactory :public Factory
	{
	public:
		virtual Adapter* BuildAdapter()
		{
			return new OraAdapter();
		}
		virtual Connection* BuildConnection()
		{
			return new OraConnection();
		}
		virtual Command* BuildCommand()
		{
			return new OraCommand();
		}
	};


	void main()
	{
		Factory *factory = new OraFactory();
		Adapter *adp = factory->BuildAdapter(); //new SqlAdapter();
		adp->CreateAdapter();
		adp->AttachAdapter();
		Connection *cnn = factory->BuildConnection(); //new SqlConnection();
		cnn->CreateConnection();
		cnn->AttachConnection();
		Command *cmd = factory->BuildCommand();//new SqlCommand();
		cmd->CreateCommand();
		cmd->AttachCommand();
	}
}