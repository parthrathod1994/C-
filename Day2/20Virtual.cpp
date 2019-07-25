#include<iostream>
using std::cout;
using std::endl;
namespace nm20
{
	class Limb
	{
	public:
		Limb()
		{
			cout << "Limb C-tor" << endl;
		}
		~Limb()
		{
			cout << "Limb D-tor" << endl;
		}
	};
	class CBase
	{
	public:
		CBase()
		{

		}
		~CBase()
		{

		}
	};
	class CA :public CBase
	{
		Limb limb;
	public:
		CA()
			//	call	??0CBase@@QAE@XZ			; CBase::CBase
			//mov	DWORD PTR [eax], OFFSET ??_7CA@@6B@
			//call	??0Limb@@QAE@XZ				; Limb::Limb
		{

		}
		virtual void fun()
		{
		}
		~CA()
			//mov	DWORD PTR [eax], OFFSET ??_7CA@@6B@
		{

		}
		//call	??1Limb@@QAE@XZ				; Limb::~Limb
		//call	??1CBase@@QAE@XZ			; CBase::~CBase
	};

	void main()
	{
		CA obj1;

	}
}