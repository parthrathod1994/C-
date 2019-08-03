#include<iostream>
#include<string>
#include<map>
using namespace std;

namespace nm23
{
	class Hindi
	{
		map<int, string> hindiRepo;
	public:
		Hindi()
		{
			hindiRepo[101] = "Namashkar";
			hindiRepo[201] = "Seb";
			hindiRepo[301] = "Chawal";
		}
		void SendInfo(string msg)
		{

		}
		void Recieve(int key)
		{
			cout << "Info recieved is " << hindiRepo[key] << endl;
		}
	};
	class English
	{
		map<int, string> englishRepo;
		Hindi *hindi;
	public:
		English(Hindi *hindi) :hindi(hindi)
		{
			englishRepo[101] = "Hello";
			englishRepo[201] = "Apple";
			englishRepo[301] = "Rice";
		}
		void SendInfo(string msg)
		{
			auto it1 = englishRepo.begin();
			auto it2 = englishRepo.end();
			int key = 0;
			while (it1 != it2)
			{
				if (msg == it1->second)
					key = it1->first;
				++it1;
			}
			hindi->Recieve(key);
		}
		void Recieve(int key)
		{
			cout << "Info recieved is " << englishRepo[key] << endl;
		}
	};

	void  main()
	{
		Hindi hindi;
		English eng(&hindi);

		eng.SendInfo("Hello");
		eng.SendInfo("Apple");
		eng.SendInfo("Rice");
	}
}