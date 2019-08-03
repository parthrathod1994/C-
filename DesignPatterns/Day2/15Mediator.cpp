#include<iostream>
#include<string>
#include<map>
using namespace std;
class IPlayer;

class ChatBroker
{
	string chat_room_name;
	map<string, IPlayer*> chat_clients;
public:
	ChatBroker(string chat_room_name) :chat_room_name(chat_room_name)
	{
		cout << "Chat Room for " << chat_room_name << endl;
	}
	void send_msg(string from, string msg, string to="");
	
	void Register(IPlayer *ply);
	
	operator ChatBroker*()
	{
		return this;
	}
};

class IPlayer
{
protected:
	IPlayer(string name):name(name)
	{
	}
	ChatBroker *chat;
	string name;
public:
	void set_chatRoom(ChatBroker *chat)
	{
		this->chat = chat;
		chat->Register(this);
	}
	virtual void send( string msg, string to="") = 0;
	virtual void Recieve(string from, string msg) = 0;
	operator IPlayer*()
	{
		return this;
	}
	string get_name() const
	{
		return name;
	}
	operator string()
	{
		return name;
	}
};

void ChatBroker::Register(IPlayer *ply)
{
	cout << ply->get_name() << " joined " << chat_room_name << " Room " << endl;
	chat_clients[ply->get_name()] = ply;
}

void ChatBroker::send_msg(string from, string msg, string to)
{
	cout << "___________________" << chat_room_name << "_____________________" << endl;
	if (to == "")
	{
		auto it1 = chat_clients.begin();
		auto it2 = chat_clients.end();
		while (it1 != it2)
		{
			if (from != it1->first)
				it1->second->Recieve(from, msg);
			it1++;
		}
	}
	else
	{
		chat_clients[to]->Recieve(from, msg);
	}
	cout << "________________________________________" << endl;
}
class Player:public IPlayer
{

public:
	Player(string name):IPlayer(name)
	{
	}
	void send( string msg, string to="")
	{
		chat->send_msg(name, msg,to);
	}
	void Recieve(string from, string msg)
	{
		cout << "( " << name << " )" << " Recieved a [ " << msg << " ] from " << from << endl;
	}
};

void main()
{
	Player dhoni("Dhoni");
	Player sewag("Sewag");
	Player rahul("Rahul");
	Player kapil("Kapil");
	Player virat("virat");

	ChatBroker chat1("TeamDiscussion");
	ChatBroker chat2("Informal Talks");
	dhoni.set_chatRoom(chat1);
	sewag.set_chatRoom(chat1);
	rahul.set_chatRoom(chat1);
	kapil.set_chatRoom(chat1);
	virat.set_chatRoom(chat1);

	virat.send("We will win ", dhoni);
	virat.send("Only me and ABD ");
}