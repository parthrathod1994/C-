#include<iostream>
using namespace std;
namespace nm04
{
	//naming conventions
	extern "C" void fun1(int k)
	{
		cout << "fun1()" << endl;
	}
	/*extern "C++"*/ void fun2(int x)//name mangling (fun2@@YAXH@Z) [name decoration]
	{
		cout << "fun2(int)" << endl;
	}
	extern "C++" void fun2(int x, int y)//name mangling (fun2@@YAXHH@Z)
	{
		cout << "fun2(int,int)" << endl;
	}
	void main()
	{
		fun1(90);
		fun2(100);//
		/*
			push	100					; 00000064H
			call	?fun2@@YAXH@Z				; fun2
			add	esp, 4
		*/
		fun2(11, 22);//
		/*
			push	22					; 00000016H
			push	11					; 0000000bH
			call	?fun2@@YAXHH@Z				; fun2
			add	esp, 8
		*/
	}
}