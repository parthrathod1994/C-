#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm13
{
	class MSP
	{
		string _make;
		string _series;
		string _processor;
	public:
		static int count;
		MSP(string make, string series, string processor)
			:_make(make), _series(series), _processor(processor)
		{
			count++;
		}
		string get_make() const
		{
			return _make;
		}
		string get_series() const
		{
			return _series;
		}
		string get_processor() const
		{
			return _processor;
		}
	};
	int MSP::count = 0;


	class MSPCache
	{
		static map<string, MSP*> repo;
		static void Register(string key, MSP *val)
		{
			repo[key] = val;
		}
	public:
		static string GetKey(string make, string series, string processor)
		{
			string key = make + series + processor;
			if (repo.find(key) == repo.end())
			{
				MSP *ptr = new MSP(make, series, processor);
				Register(key, ptr);
			}
			return key;
		}
		static MSP* GetMSP(string key)
		{
			return repo[key];
		}
	};
	map<string, MSP*> MSPCache::repo;

	class Computer
	{
		string _ram;
		string _hd;
		string _monitor;
		string key;

	public:
		static int count;
		Computer(string ram,
			string hd,
			string processor,
			string make,
			string monitor,
			string series) :_ram(ram), _hd(hd), _monitor(monitor), key(MSPCache::GetKey(make, series, processor))
		{
			count++;
		}
		void Display() const
		{
			MSP *msp = MSPCache::GetMSP(key);
			cout << "Make       = " << msp->get_make() << endl;
			cout << "Series     = " << msp->get_series() << endl;
			cout << "Processor  = " << msp->get_processor() << endl;
			cout << "Ram        = " << _ram << endl;
			cout << "HD         = " << _hd << endl;
			cout << "Monitor    = " << _monitor << endl;
			cout << "____________________________________" << endl;
		}
	};
	int Computer::count = 0;

	void main()
	{
		Computer comp1("16gb", "1tb", "intel", "dell", "15inch", "lattitude");
		Computer comp2("8gb", "0.5tb", "intel", "dell", "15inch", "lattitude");
		Computer comp3("32gb", "1tb", "cellron", "hp", "15inch", "flash");
		Computer comp4("8gb", "0.5tb", "intel", "dell", "15inch", "lattitude");
		Computer comp5("16gb", "1tb", "cellron", "hp", "15inch", "flash");
		Computer comp6("32gb", "0.5tb", "intel", "dell", "15inch", "lattitude");

		for (auto & x : { comp1,comp2,comp3,comp4,comp5,comp6 })
		{
			x.Display();
		}
		cout << "Computer::count =" << Computer::count << endl;
		cout << "MSP::count      =" << MSP::count << endl;
		cout << "____________________________________" << endl;
	}
}