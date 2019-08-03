#include<iostream>
#include<map>
using namespace std;
namespace nm10_1
{
	class File
	{
	public:
		virtual void ProcessFile() = 0;
	};
	class BMP :public File//10
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
	class JPEG :public File//20
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

	class FileFactory
	{
	protected:
		virtual File* CreateActualFileObject() = 0;
	public:
		File* CreateFile()
		{
			cout << "Pre Object construction (General)" << endl;
			File* temp = CreateActualFileObject();
			cout << "Post Object construction (General)" << endl;
			return temp;
		}
	};
	class BMPFactory :public FileFactory
	{
	protected:
		File* CreateActualFileObject()
		{
			cout << "Pre BMP Object construction (Specific)" << endl;
			File * bmp = new BMP();
			cout << "Post BMP Object construction (Specific)" << endl;
			return bmp;
		}
	};
	class JpegFactory :public FileFactory
	{
	protected:
		File* CreateActualFileObject()
		{
			cout << "Pre Jpeg Object construction (Specific)" << endl;
			File * jpeg = new JPEG();
			cout << "Post Jpeg Object construction (Specific)" << endl;
			return jpeg;
		}
	};
	class WMFFactory :public FileFactory
	{
	protected:
		File* CreateActualFileObject()
		{
			cout << "Pre WMF Object construction (Specific)" << endl;
			File * wmf = new WMF();
			cout << "Post WMF Object construction (Specific)" << endl;
			return wmf;
		}
	};

	class PNGFactory :public FileFactory
	{
	protected:
		File* CreateActualFileObject()
		{
			cout << "Pre PNG Object construction (Specific)" << endl;
			File * png = new PNG();
			cout << "Post PNG Object construction (Specific)" << endl;
			return png;
		}
	};

	using FPTR = FileFactory*(*)();
	class Factory //static class 
	{
		static map<int, FPTR> repo;
	public:
		static File* CreateFileObject(int key)
		{
			FPTR fact = repo[key];
			FileFactory* factObj = fact();
			File* temp = factObj->CreateFile();
			delete factObj;
			cout << "______________________" << endl;
			return temp;
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
			Factory::Register(10, []()->FileFactory* {return new BMPFactory(); });
			Factory::Register(20, []()->FileFactory* {return new JpegFactory(); });
			Factory::Register(30, []()->FileFactory* {return new WMFFactory(); });
			Factory::Register(40, []()->FileFactory* {return new PNGFactory(); });

		}
	}dummy;


	void main()
	{
		File *file = Factory::CreateFileObject(20);

		file->ProcessFile();
	}
}