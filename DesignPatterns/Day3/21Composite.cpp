#include<iostream>
#include<string>
#include<vector>
using namespace std;
namespace nm21
{
	class IShow
	{
	public:
		virtual void Display() = 0;
	};
	class Player :public IShow
	{
		string name;
	public:
		Player(string name) :name(name)
		{
		}
		void Display()
		{
			cout << "\t\t\t\t\t" << name << endl;
		}
	};
	class PlayersList :public vector<Player*>
	{
	public:
		PlayersList()
		{
		}
	};

	class Team :public IShow
	{
		PlayersList ply_list;
		string name;
	public:
		Team(string name) :name(name)
		{
		}
		void AddPlayer(string player_name)
		{
			ply_list.push_back(new Player(player_name));
		}
		void Display()
		{
			cout << "\t\t\t\t" << name << endl;
			PlayersList::iterator it1 = ply_list.begin();
			PlayersList::iterator it2 = ply_list.end();
			while (it1 != it2)
			{
				(*it1)->Display();
				++it1;
			}
		}
	};

	class TeamList :public vector<Team*>
	{
	public:
		TeamList()
		{
		}
	};

	class Division :public IShow
	{
		TeamList team_list;
		string name;
	public:
		Division(string name) :name(name)
		{
		}
		void AddTeam(string team_name)
		{
			team_list.push_back(new Team(team_name));
		}
		Team& operator[](int index)
		{
			return *team_list.at(index);
		}
		void Display()
		{
			cout << "\t\t" << name << endl;
			auto it1 = team_list.begin();
			auto it2 = team_list.end();
			while (it1 != it2)
			{
				(*it1)->Display();
				++it1;
			}
		}
	};

	class DivisionList :vector<Division*>
	{
	public:
		DivisionList()
		{
		}
		void AddDivision(string name)
		{
			push_back(new Division(name));
		}
		void Display()
		{
			auto it1 = begin();
			auto it2 = end();
			while (it1 != it2)
			{
				(*it1)->Display();
				++it1;
			}
		}
		Division& operator[](int index)
		{
			return *at(index);
		}
	};

	void main()
	{
		DivisionList div1;
		div1.AddDivision("AlphaDiv");
		div1.AddDivision("BetaDiv");
		div1.AddDivision("Gamma");

		Division& d1 = div1[0];
		d1.AddTeam("RCB");
		d1.AddTeam("KKR");
		Team& t1 = d1[0];
		t1.AddPlayer("ABD");
		t1.AddPlayer("Kohli");
		t1.AddPlayer("Uthapa");
		Team& t2 = d1[1];
		t1.AddPlayer("Karthick");
		t1.AddPlayer("Saurav");
		t1.AddPlayer("Yuvraj");


		Division& d2 = div1[1];
		d2.AddTeam("Pune");
		d2.AddTeam("Kerala");
		Team& tt1 = d2[0];
		tt1.AddPlayer("Sewag");
		tt1.AddPlayer("Sachin");
		tt1.AddPlayer("Bumra");
		Team& tt2 = d2[1];
		tt2.AddPlayer("Srishanth");
		tt2.AddPlayer("Samson");
		tt2.AddPlayer("Iyer");

		div1.Display();

	}
}