#include<iostream>
using namespace std;

namespace nm15
{
	class CBase
	{
	private:
		int pvt = 10;
	protected:
		int prot = 20;
	public:
		int pub = 30;
		void DispCBase() const
		{
			cout << "____________CBase::Display______________\n";
			cout << "pvt  = " << pvt << endl;
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
		friend class CDerivedFour;//vertical access control
	};
	class CDerivedOne :public CBase
	{
	public:
		void DispOne() const
		{
			cout << "____________CDerivedOne::Display______________\n";
			//cout << "pvt  = " << pvt << endl;
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};
	class CDerivedMostOne :public CDerivedOne
	{
	public:
		void DispMostOne() const
		{
			cout << "____________CDerivedMostOne::Display______________\n";
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};

	class CDerivedTwo :protected CBase
	{
	public:
		void DispTwo() const
		{
			cout << "____________CDerivedTwo::Display______________\n";
			//cout << "pvt  = " << pvt << endl;
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};
	class CDerivedMostTwo :public CDerivedTwo
	{
	public:
		void DispMostTwo() const
		{
			cout << "____________CDerivedMostTwo::Display______________\n";
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};

	class CDerivedThree :private CBase
	{
	public:
		void DispThree() const
		{
			cout << "____________CDerivedThree::Display______________\n";
			//cout << "pvt  = " << pvt << endl;
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};
	class CDerivedMostThree :public CDerivedThree
	{
	public:
		void DispMostThree() const
		{
			cout << "____________CDerivedMostThree::Display______________\n";
			//cout << "prot = " << prot << endl;
			//cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};

	class CDerivedFour :private CBase
	{
	public:
		void DispFour() const
		{
			cout << "____________CDerivedFour::Display______________\n";
			cout << "pvt  = " << pvt << endl;//vertical access control
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};

	class CDerivedFive :public CBase
	{
	private:
		using CBase::prot;//vertical access control
	protected:
		CBase::pub;//using keyword is optional (vertical access control)
	public:
		void DispFour() const
		{
			cout << "____________CDerivedFive::Display______________\n";
			cout << "prot = " << prot << endl;
			cout << "pub  = " << pub << endl;
			cout << "____________________________________________";
		}
	};

	void main()
	{
		CBase cb;
		cb.pub = 999;
		cb.DispCBase();
		CDerivedOne cdo;
		cdo.pub = 888;
		cdo.DispOne();
		CDerivedTwo cdt;
		//cdt.pub = 777;
		cdt.DispTwo();
	}
}