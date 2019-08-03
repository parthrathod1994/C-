#include<iostream>
using namespace std;
namespace nm11_1
{
	class SigleTon
	{
	protected:
		SigleTon()
		{
			cout << "Singleton Created " << endl;
		}
		~SigleTon()
		{
			cout << "Singleton Released " << endl;
		}
	private:
		static SigleTon *head;
		static SigleTon* CreateSingleton()
		{
			if (NULL == head)
				head = new SigleTon();
			return head;
		}
		friend class SmartPTR;
	public:
		void DoJob()
		{
			cout << "Sigleton Performing the job" << endl;
		}
	};
	SigleTon * SigleTon::head = NULL;

	class SmartPTR
	{
		static void* operator new(size_t size)
		{
		}
		static void* operator new[](size_t size)
		{
		}
			static void operator delete(void *pv)
		{
		}
		static void operator delete[](void *pv)
		{
		}
		SigleTon *pt;
		static int count;
	public:
		SmartPTR() :pt(SigleTon::CreateSingleton())
		{
			count++;
		}
		SmartPTR(const SmartPTR & par) :pt(par.pt)
		{
			count++;
		}
		SmartPTR & operator=(const SmartPTR&) = delete;
		SigleTon* operator->()
		{
			return pt;
		}
		~SmartPTR()
		{
			count--;
			if (count == 0)
			{
				delete pt;
			}
		}
	};
	int SmartPTR::count = 0;


	void main()
	{
		SmartPTR pt1;
		pt1->DoJob();
		SmartPTR pt2;
		SmartPTR pt3 = pt2;
	}
}