#include<iostream>
#include<string>
#include<map>
#include<any>
using namespace std;
namespace nm20
{
	class CareTaker
	{
		map<void*, map<string, any>> repo;
	public:
		void SaveSate(void* key, map<string, any> val)
		{
			repo[key] = val;
		}
		map<string, any> GetState(void* key)
		{
			return repo[key];
		}
		operator CareTaker*()
		{
			return this;
		}
	};


	class StatePersist
	{
	protected:
		CareTaker *taker;
	public:
		void Set_CareTaker(CareTaker *taker)
		{
			this->taker = taker;
		}
		virtual void Hyderate() = 0;
		virtual void Dehyderate() = 0;

	};

	class Player :public StatePersist
	{
	public:
		int id;
		string name;
		double salary;
		void Display()
		{
			cout << "--------------------Player Info----------------" << endl;
			cout << " Id     =" << id << endl;
			cout << " name   =" << name << endl;
			cout << " salary =" << salary << endl;
			cout << "__________________________________" << endl;
		}
		virtual void Hyderate()
		{
			map<string, any> state;
			any copy_id = id;
			any copy_name = name;
			any copy_salary = salary;
			state["id"] = copy_id;
			state["name"] = copy_name;
			state["salary"] = copy_salary;
			taker->SaveSate(this, state);
		}
		virtual void Dehyderate()
		{
			map<string, any> state = taker->GetState(this);
			this->id = any_cast<int>(state["id"]);
			this->name = any_cast<string>(state["name"]);
			this->salary = any_cast<double>(state["salary"]);
		}
	};

	class Customer :public StatePersist
	{
	public:
		string cust_id;
		string name;
		int points;
		void Display()
		{
			cout << "--------------------Customer Info----------------" << endl;
			cout << " Cust_Id  =" << cust_id << endl;
			cout << " Name     =" << name << endl;
			cout << " Points   =" << points << endl;
			cout << "__________________________________" << endl;
		}
		virtual void Hyderate()
		{
			map<string, any> state;
			state["cust_id"] = cust_id;
			state["name"] = name;
			state["points"] = points;
			taker->SaveSate(this, state);
		}
		virtual void Dehyderate()
		{
			map<string, any> state = taker->GetState(this);
			this->cust_id = any_cast<string>(state["cust_id"]);
			this->name = any_cast<string>(state["name"]);
			this->points = any_cast<int>(state["points"]);
		}
	};


	void main()
	{
		CareTaker care_taker;
		Player ply1;
		ply1.Set_CareTaker(care_taker);
		ply1.id = 101;
		ply1.name = "sachin";
		ply1.salary = 10000;

		Player ply2;
		ply2.Set_CareTaker(care_taker);
		ply2.id = 102;
		ply2.name = "virat";
		ply2.salary = 50000;

		ply2.Hyderate();

		ply2.name = "Kohli";
		ply2.salary = 40000;

		Customer cust1;
		cust1.Set_CareTaker(care_taker);
		cust1.cust_id = "sa123";
		cust1.name = "sharukh";
		cust1.points = 543;

		Customer cust2;
		cust2.Set_CareTaker(care_taker);
		cust2.cust_id = "sa345";
		cust2.name = "naser";
		cust2.points = 123;

		cust2.Hyderate();
		cust2.name = "Babaji";
		cust2.points = 456;

		ply1.Display();
		ply2.Display();
		cust1.Display();
		cust2.Display();

		cout << "==================================================" << endl;
		ply2.Dehyderate();
		cust2.Dehyderate();
		ply2.Display();
		cust2.Display();

	}
}