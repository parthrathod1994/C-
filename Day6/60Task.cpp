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
//Dirty code (Dry / SRP)
namespace nm60
{
	class Savings
	{
	public:
		void DoSavingsJob()
		{
			cout << "Open DB" << endl;
			cout << "Savings job done " << endl;
			cout << "Close DB" << endl;
		}
	};
	class Current {
	public:
		void DoCurrentJob()
		{
			cout << "Open DB" << endl;
			cout << "Current job done " << endl;
			cout << "Close DB" << endl;
		}
	};

	void main()
	{
		Savings sa;
		sa.DoSavingsJob();
		cout << "__________________________________\n";
		Current curr;
		curr.DoCurrentJob();
	}
}