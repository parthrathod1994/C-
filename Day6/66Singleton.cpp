#include<iostream>
#include<string>
using namespace std;
namespace nm66
{
	class CA
	{
		CA()
		{
			cout << "CA Ctor\n";
		}
		~CA()
		{
			cout << "CA D-tor\n";
		}
		static CA* GetInstance()//Creator / factory
		{
			if (head == NULL)
				head = new CA();
			return head;
		}
		static void Release()
		{
			delete head;
			head = NULL;
		}
		static CA* head;
	public:
		CA(const CA&) = delete;
		CA& operator=(const CA&) = delete;
		void fun()
		{
			cout << "CA Fun\n";
		}
		friend class ShubhangiSmart;
	};
	CA* CA::head = NULL;
	class ShubhangiSmart
	{
		static void* operator new(size_t size)
		{
			return NULL;
		}
		static void* operator new[](size_t size)
		{
			return NULL;
		}
			static void operator delete(void *pv)
		{

		}
		static void operator delete[](void *pv)
		{

		}
		CA *ptr;
		static int count;
	public:
		ShubhangiSmart() :ptr(CA::GetInstance())
		{
			count++;
		}
		ShubhangiSmart(const ShubhangiSmart &par) :ptr(par.ptr)
		{
			count++;
		}

		CA* operator->()
		{
			return ptr;
		}
		CA* operator&()
		{
			return ptr;
		}
		~ShubhangiSmart()
		{
			count--;
			if (count == 0)
			{
				CA::Release();
			}
		}
	};
	int ShubhangiSmart::count = 0;

	void SimpleFun(ShubhangiSmart sp)
	{

		sp->fun();
	}

	void main()
	{

		cout << "____________________________\n";
		ShubhangiSmart sp1;
		SimpleFun(sp1);
		ShubhangiSmart sp2;// = new ShubhangiSmart();
		ShubhangiSmart sp3;
		sp1->fun();
		CA* pt = &sp1;
	}
}