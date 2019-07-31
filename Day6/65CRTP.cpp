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

namespace nm65
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

	template<typename T>
	class Account //Abstract class 
	{
		DB *db;
	public:
		void SetDB(DB *db)
		{
			this->db = db;
		}

		void DoJob()
		{
			db->OpenDB();
			((T*)this)->ActualJob();
			db->CloseDb();
		}
	};

	class Savings :public Account<Savings>
	{
	public:
		void ActualJob()
		{
			cout << "Savings job done " << endl;
		}
	};
	class Current :public Account<Current> {

	public:
		void ActualJob()
		{
			cout << "Current job done " << endl;
		}
	};

	void main()
	{
		DB db;
		Savings sa;
		sa.SetDB(&db);
		sa.DoJob();
		cout << "__________________________________\n";
		Current curr;
		curr.SetDB(&db);
		curr.DoJob();
	}
}