#include<iostream>
#include<string>
#include<map>
using namespace std;
namespace nm57
{
	struct MSP
	{
		MSP(string manufacturer, string series, string processor) :manufacturer(manufacturer),
			series(series),
			processor(processor)
		{
			count++;
		}
		static map<string, MSP*> repo;
		string manufacturer;
		string series;
		string processor;
		static int count;
	};
	map<string, MSP*> MSP::repo;
	int MSP::count = 0;



	MSP* CreateMSP(string manufacturer, string series, string processor)
	{
		string key = manufacturer + series + processor;
		if (MSP::repo.find(key) == MSP::repo.end())
		{
			MSP::repo[key] = new MSP(manufacturer, series, processor);
		}
		return MSP::repo[key];
	}

	class Computer
	{
		string ram;
		string hd;
		string monitor;
		MSP *msp;
	public:
		static int count;
		Computer(string manufacturer,
			string series,
			string processor,
			string ram,
			string hd,
			string monitor) : ram(ram),
			hd(hd),
			monitor(monitor),
			msp(CreateMSP(manufacturer, series, processor))
		{
			count++;
		}
		void Display()
		{
			cout << msp->manufacturer << "\t" << msp->series << "\t" << msp->processor << "\t" << ram << "\t" << hd << "\t" << monitor << "\n";
			cout << "________________________________________________________\n";
		}
	};

	int Computer::count = 0;

	void main()
	{
		Computer c1("dell", "lattitude", "intel", "64gb", "1tb", "13inch");
		Computer c2("dell", "lattitude", "intel", "32gb", "0.5tb", "11inch");
		Computer c3("hp", "flash", "cellron", "16gb", "1.5tb", "15inch");
		Computer c4("dell", "lattitude", "intel", "128gb", "2tb", "11inch");
		Computer c5("dell", "lattitude", "intel", "64gb", "1tb", "15inch");
		Computer c6("hp", "flash", "cellron", "64gb", "0.5tb", "13inch");

		c1.Display();
		c2.Display();
		c3.Display();
		c4.Display();
		c5.Display();
		c6.Display();

		cout << "The computer count = " << Computer::count << endl;
		cout << "The MSP      count = " << MSP::count << endl;
	}
}