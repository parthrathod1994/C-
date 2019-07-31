#include<iostream>
#include<string>
using namespace std;
namespace nm69
{
	class CBase
	{
	public:
		virtual void ClientJob() = 0;
	};
	void VendorFun(CBase *cb)
	{
		cout << "Vendor Job started \n";
		cb->ClientJob();
		cout << "Vendor Job completed \n________________________________________________\n";
	}
	//-------------------------------------------
	//function

	class CA :public CBase
	{
	public:
		void ClientJob()
		{
			cout << "Client job done " << endl;
		}
	};

	void main()
	{
		CA obj;
		VendorFun(&obj);
	}
}