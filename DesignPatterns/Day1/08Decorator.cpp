#include<iostream>
#include<string>
using namespace std;
namespace nm08
{
	class ILogger
	{
	public:
		virtual void LogMessage(string msg) = 0;
	};

	class NullLogger :public ILogger
	{
	public:
		void LogMessage(string msg)
		{
			//do nothing
		}
	};
	//----------------------------
	class Decorator :public ILogger
	{
		ILogger *il;
	public:
		Decorator(ILogger *il) :il(il)
		{
		}
		void LogMessage(string msg)
		{
			il->LogMessage(msg);//traversal
		}
	};

	//----------------------------
	class FileLogger :public Decorator
	{
	public:
		FileLogger(ILogger *il) :Decorator(il)
		{
		}
		void LogMessage(string msg)
		{
			cout << "File Logger logged [ " << msg << "] " << endl;
			Decorator::LogMessage(msg);
		}
	};



	class ConsoleLogger :public Decorator
	{
	public:
		ConsoleLogger(ILogger *il) :Decorator(il)
		{
		}
		void LogMessage(string msg)
		{
			cout << "Console Logger logged [ " << msg << "] " << endl;
			Decorator::LogMessage(msg);
		}
	};
	class ServiceLogger :public Decorator
	{
	public:
		ServiceLogger(ILogger *il) :Decorator(il)
		{
		}
		void LogMessage(string msg)
		{
			cout << "Service Logger logged [ " << msg << "] " << endl;
			Decorator::LogMessage(msg);
		}
	};

	//Factory
	class LoggerFactory
	{
	public:
		static ILogger * CreateLoggers()
		{
			//return new NullLogger();
			//return new FileLogger();
			//return new ConsoleLogger();
			//return new ServiceLogger();
			return new ServiceLogger(new FileLogger(new ConsoleLogger(new NullLogger())));
		}
	};

	//------------------Consumer----------

	class CustomLogger :public Decorator
	{
	public:
		CustomLogger(ILogger *il) :Decorator(il)
		{
		}
		void LogMessage(string msg)
		{
			cout << "Custom Logger logged [ " << msg << "] " << endl;
			Decorator::LogMessage(msg);
		}
	};


	class Encoder :public Decorator
	{
	public:
		Encoder(ILogger *il) :Decorator(il)
		{
		}
		void LogMessage(string msg)
		{
			cout << "Encoder for [ " << msg << "] " << endl;
			Decorator::LogMessage(msg);
		}
	};
	void main()
	{
		ILogger *il = new Encoder(new CustomLogger(LoggerFactory::CreateLoggers()));
		cout << "Business started " << endl;
		il->LogMessage("CSK & SRH");
		cout << "Business completed " << endl;
	}
}