#include<iostream>
#include<map>
using namespace std;
namespace nm10{
class File
{
public:
	virtual void ProcessFile() = 0;
};
class BMP:public File//10
{
public:
	BMP()
	{
		cout << "BMP object constructed " << endl;
	}
	virtual void ProcessFile()
	{
		cout << "Processing BMP" << endl;
	}
};
class JPEG:public File//20
{
public:
	JPEG()
	{
		cout << "JPEG object constructed " << endl;
	}
	virtual void ProcessFile()
	{
		cout << "Processing JPEG" << endl;
	}
};

class WMF :public File//30
{
public:
	WMF()
	{
		cout << "WMF object constructed " << endl;
	}
	virtual void ProcessFile()
	{
		cout << "Processing WMF" << endl;
	}
};
class PNG :public File//40
{
public:
	PNG()
	{
		cout << "PNG object constructed " << endl;
	}
	virtual void ProcessFile()
	{
		cout << "Processing PNG" << endl;
	}
};
using FPTR = File*(*)();
class Factory //static class 
{
	static map<int, FPTR> repo;
public:
	static File* CreateFileObject(int key)
	{
		FPTR val = repo[key];
		File* obj = val();
		return obj;
	}
	static void Register(int key, FPTR val)
	{
		repo[key] = val;
	}
	static void UnRegister(int key)
	{
		repo.erase(key);
	}
};
map<int, FPTR> Factory::repo;
class Dummy
{
public:
	Dummy()
	{
		cout << "Pre Object construction " << endl;
		Factory::Register(10, []()->File* {return new BMP(); });
		Factory::Register(20, []()->File* {return new JPEG(); });
		Factory::Register(30, []()->File* {return new WMF(); });
		Factory::Register(40, []()->File* {return new PNG(); });
		cout << "Post Object construction " << endl;
	}
};// dummy;


void main()
{
	File *file = Factory::CreateFileObject(40);
	file->ProcessFile();
}
}
