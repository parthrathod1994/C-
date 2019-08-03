#include<iostream>
#include<string>
using namespace std;

/*
1. normal card
2. silver card
3. gold card
4. platinum
*/
namespace nm18
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


	class CardHolderFactory
	{
	public:
		static CardHolder* GetCard(int amount)
		{
			if (amount < 200000)
				return new NormalCard();
			else if (amount < 500000)
			{
				return new SilverCard();
			}
			return new GoldCard();
		}
	};

	class Account
	{
		int amount;
		CardHolder *holder;
	public:
		void CardStatus()
		{
			holder = CardHolderFactory::GetCard(this->amount);
			holder->Facilities();
		}
		Account(int amount) :amount(amount)
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
		Account acc(700000);
		acc.Withdraw(250000);
		acc.Withdraw(250001);
	}
}