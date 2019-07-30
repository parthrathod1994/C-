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
//Dirty Code (Violating Principles)
/*
void DoDebit(int accId,int amount)
{

}
*/
class Account
{
public:
	void DoSavingsJob()
	{
		cout << "Savings job done " << endl;
	}
	void DoCurrentJob()
	{
		cout << "Current job done " << endl;
	}
};

void main()
{
	Account acc;
	acc.DoCurrentJob();
	acc.DoSavingsJob();
}