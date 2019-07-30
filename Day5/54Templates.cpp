#include<iostream>
using namespace std;
//generic (template)
//template bloating (not accepted)
namespace nm54
{
	template<typename T>
	class Stack
	{
		T arr[5];
		int top;
	public:
		Stack() :top(-1)
		{
			cout << "Stack ctor for " << typeid(T).name() << endl;//RTTI
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
		bool IsEmpty()
		{
			return top == -1;
		}
		bool IsFull()
		{
			return top == 4;
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