#include<iostream>
using namespace std;
namespace nm55
{
	//Allways avoid template bloating
	class StackBase
	{
	protected:
		int top;
		StackBase() :top(-1)
		{
		}
	public:
		bool IsEmpty()
		{
			return top == -1;
		}
		bool IsFull()
		{
			return top == 4;
		}
	};

	template<typename T>
	class Stack :public StackBase
	{
		T arr[5];
	public:
		Stack()
		{
			cout << "Stack ctor for " << typeid(T).name() << endl;
		}
		void Push(T val)
		{
			arr[++top] = val;
		}
		T Pop()
		{
			return arr[top--];
		}
		T Peek()
		{
			return arr[top];
		}

	};

	void main()
	{
		Stack<int> obj1;
		Stack<double> obj2;
		Stack<char*> obj3;
		Stack<double> obj4;
	}
}