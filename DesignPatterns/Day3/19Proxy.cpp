#include<iostream>
#include<string>
#include<map>
using namespace std;

namespace nm19
{
	class CardHolder
	{
	protected:
		string card_holder_type;
		CardHolder(string card_holder_type) :card_holder_type(card_holder_type)
		{
			cout << "Object contructed for " << card_holder_type << endl;
		}
	public:
		virtual void Facilities() = 0;
	};

	class NormalCard :public CardHolder
	{
	public:
		NormalCard() :CardHolder("Normal Card")
		{
		}
		void Facilities()
		{
			cout << "You are holding --------" << card_holder_type << "----------" << endl;
			cout << "Do shopping and get 100 rs back" << endl;
			cout << "Swipe this for petrol and get 1% cash back" << endl;
			cout << "Get Instant loan of 1 lk rupees" << endl;
			cout << "_______________________________________" << endl;
		}
	};

	class SilverCard :public CardHolder
	{
	public:
		SilverCard() :CardHolder("Silver Card")
		{
		}
		void Facilities()
		{
			cout << "You are holding --------" << card_holder_type << "----------" << endl;
			cout << "Buy a car at least interest" << endl;
			cout << "Buy from amazon for amzing offers" << endl;
			cout << "Get Instant loan of 5 lk rupees" << endl;
			cout << "_______________________________________" << endl;
		}
	};

	class GoldCard :public CardHolder
	{
	public:
		GoldCard() :CardHolder("Gold Card")
		{
		}
		void Facilities()
		{
			cout << "You are holding --------" << card_holder_type << "----------" << endl;
			cout << "Take an insurance through card" << endl;
			cout << "Hoam loans provided for you" << endl;
			cout << "Convert your purchase above 1 lk into EMI" << endl;
			cout << "_______________________________________" << endl;
		}
	};


	class CardRepo
	{
		static map<int, CardHolder*> repo;
	public:
		CardRepo()
		{

		}
		static void Register(int key, CardHolder* val)
		{
			repo[key] = val;
		}

		static CardHolder* GetCard(int key)
		{
			return repo[key];
		}

	};
	map<int, CardHolder*> CardRepo::repo;
	class Dummy
	{
	public:
		Dummy()
		{
			CardRepo::Register(10, new NormalCard());
			CardRepo::Register(20, new SilverCard());
			CardRepo::Register(30, new GoldCard());
		}
	};// dummy;

	class CardHolderFactory
	{
	public:

		static CardHolder* GetCard(int amount)
		{
			if (amount < 200000)
				return CardRepo::GetCard(10);
			else if (amount < 500000)
			{
				return CardRepo::GetCard(20);
			}
			return CardRepo::GetCard(30);
		}
	};

	class SmartPtr
	{
		CardHolder *holder;
	public:
		SmartPtr(int amount) :holder(CardHolderFactory::GetCard(amount))
		{
		}
		SmartPtr& operator=(int amount)
		{
			holder = CardHolderFactory::GetCard(amount);
			return *this;
		}
		CardHolder* operator->()
		{
			return holder;
		}

	};

	class Account
	{
		int amount;
		SmartPtr smpt;
	public:
		void CardStatus()
		{
			smpt = amount;
			smpt->Facilities();
		}
		Account(int amount) :amount(amount), smpt(amount)
		{
			CardStatus();
		}
		void Withdraw(int amount)
		{
			this->amount -= amount;
			CardStatus();
		}
		void Deposit(int amount)
		{
			this->amount += amount;
			CardStatus();
		}
	};

	void main()
	{
		cout << "______________________________" << endl;
		Account acc(700000);
		acc.Withdraw(250000);
		acc.Withdraw(250001);
	}
}