#include<iostream>
#include<string>
using namespace std;
/*
1.  YAGNI -> You arn't gonna need it
2.  KISS  -> Keep It Simple and Stupid
3.  DRY or DIE -> Don't Repeat Yourself or Duplication is evil
4.  High Cohession
5.  Low Coupling
6.  SRP -> single Responsibility Priciple
7.  OCP -> Open Close Principle
8.  LOD -> Law of demeter
9.  LSP -> Liskov Substitution Priciple
10. DIP -> Dipendency Inversion Principle (IOC -> Inveriosn of Control)
11. Cyclomatic Complexity
12. NULL Object
13. Value Object
14. Information Expert
15. Pure Fabrication
16. ISP -> Interface Segregation Principle
17. Controller
18. Factory / Creator
*/
//Dirty code (Dry)
namespace nm62
{
	class DB
	{
	public:
		void OpenDB()
		{
			cout << "Open DB" << endl;
		}
		void CloseDb()
		{
			cout << "Close DB" << endl;
		}
	};

	class Savings
	{
		DB *db;
	public:
		void SetDB(DB *db)
		{
			this->db = db;
		}
		void DoSavingsJob()
		{
			db->OpenDB();
			cout << "Savings job done " << endl;
			db->CloseDb();
		}
	};
	class Current {
		DB *db;
	public:
		void SetDB(DB *db)
		{
			this->db = db;
		}
		void DoCurrentJob()
		{
			db->OpenDB();
			cout << "Current job done " << endl;
			db->CloseDb();
		}
	};

	void main()
	{
		DB db;
		Savings sa;
		sa.SetDB(&db);
		sa.DoSavingsJob();
		cout << "__________________________________\n";
		Current curr;
		curr.SetDB(&db);
		curr.DoCurrentJob();
	}
}