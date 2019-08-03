#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm14
{
	class INotify
	{
		string name;
	protected:
		INotify(string name) :name(name)
		{
		}
	public:
		virtual void Notify(string info) = 0;
		operator INotify*()
		{
			return this;
		}
		string getName() const
		{
			return name;
		}

	};

	class DD :public INotify
	{
	public:
		DD() :INotify("DD")
		{

		}
		void Notify(string info)
		{
			cout << "(DD) recieved " << info << endl;
		}
	};

	class NDTV :public INotify
	{
	public:
		NDTV() :INotify("NDTV")
		{

		}
		void Notify(string info)
		{
			cout << "(NDTV) recieved " << info << endl;
		}
	};

	class Zee :public INotify
	{
	public:
		Zee() :INotify("Zee")
		{

		}
		void Notify(string info)
		{
			cout << "(Zee) recieved " << info << endl;
		}
	};

	class Publisher
	{
	protected:
		string name;
		map<string, INotify*> subscribers;
		void BroadCast(string info)
		{
			cout << "_____________________________" << endl;
			auto it1 = subscribers.begin();
			auto it2 = subscribers.end();
			//broadcasting
			while (it1 != it2)
			{
				it1->second->Notify(name + " : " + info);
				it1++;
			}
			cout << "_____________________________" << endl;
		}
		Publisher(string name) :name(name)
		{

		}
	public:
		void Subscribe(INotify *client)
		{
			subscribers[client->getName()] = client;
		}
	};

	class Election :public Publisher
	{
	public:
		Election() :Publisher("Election : ")
		{

		}
		void ElectionResult(string info)
		{
			BroadCast(info);
		}
	};

	class Entertainment :public Publisher
	{
	public:
		Entertainment() :Publisher("Entertainment : ")
		{

		}
		void EntertainmentNews(string info)
		{
			BroadCast(info);
		}
	};
	class Sports :public Publisher
	{
	public:
		Sports() :Publisher("Entertainment : ")
		{

		}
		void SportsNews(string info)
		{
			BroadCast(info);
		}
	};

	void main()
	{
		DD dd;
		NDTV ndtv;
		Zee zee;

		Election elec;
		Entertainment entertain;
		Sports spts;

		elec.Subscribe(dd);
		elec.Subscribe(ndtv);
		elec.Subscribe(zee);

		entertain.Subscribe(ndtv);
		entertain.Subscribe(zee);

		spts.Subscribe(dd);
		spts.Subscribe(zee);

		elec.ElectionResult("Huge Copetetion between RPI BJP Congress");
		entertain.EntertainmentNews("New movie for kamal hasan");
		spts.SportsNews("RCB might win tommorrow");
	}
}