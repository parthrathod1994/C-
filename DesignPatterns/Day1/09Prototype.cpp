#include<iostream>
#include<map>
using namespace std;
class Register
{
	//additional business for construction
};
class ObjectPool
{
	static map<int, ObjectPool*> pool;
protected:
	ObjectPool(Register&, int key)
	{
		pool[key] = this;
	}
	ObjectPool(ObjectPool&)
	{
	}
	virtual ObjectPool* Clone() = 0;
public:
	virtual void DoJob() = 0;
	static ObjectPool* GetObject(int key)
	{
		return pool[key]->Clone();
	}
};
map<int, ObjectPool*> ObjectPool::pool;

class Currency:public ObjectPool
{
	Currency(Currency& c) :ObjectPool(c)
	{
		cout << "Currency cloned" << endl;
	}
public:
	Currency(Register &reg):ObjectPool(reg,101)
	{
		cout << "Curreny registered" << endl;
	}
	ObjectPool* Clone()
	{
		return new Currency(*this);
	}
	void DoJob()
	{
		cout << "Currency info worked" << endl;
	}
};

class Weather :public ObjectPool
{
	Weather(Weather& c) :ObjectPool(c)
	{
		cout << "Weather cloned" << endl;
	}
public:
	Weather(Register &reg) :ObjectPool(reg, 102)
	{
		cout << "Weather registered" << endl;
	}
	ObjectPool* Clone()
	{
		return new Weather(*this);
	}
	void DoJob()
	{
		cout << "Weather info worked" << endl;
	}
};
class SMSProvider :public ObjectPool
{
	SMSProvider(SMSProvider& c) :ObjectPool(c)
	{
		cout << "SMSProvider cloned" << endl;
	}
public:
	SMSProvider(Register &reg) :ObjectPool(reg, 103)
	{
		cout << "SMSProvider registered" << endl;
	}
	ObjectPool* Clone()
	{
		return new SMSProvider(*this);
	}
	void DoJob()
	{
		cout << "SMSProvider info worked" << endl;
	}
};

class Dummy
{
public:
	Dummy()
	{
		Register reg;
		new Currency(reg);
		new Weather(reg);
		new SMSProvider(reg);
	}
}dummy;

void main()
{
	cout << "________________________" << endl;
	ObjectPool *obj = ObjectPool::GetObject(102);
	obj->DoJob();
}