#include<iostream>
#include<string>
using namespace std;
namespace nm73
{
	//HOF (Higher order functions)
	auto Greet(string msg)
	{
		return [msg](string sep) {
			return [sep, msg](string name) {//Currying
				cout << msg << sep << name << endl;
			};
		};
	}

	void main()
	{
		//Greet("Welcome")("---->")("Sachin");

		auto nmFn = Greet("Welcome")("---->");

		nmFn("Virat");
		nmFn("Rohith");
		nmFn("Rahul");
		nmFn("Sewag");
		nmFn("Pandya");
		nmFn("Chahal");
		auto sepFun = Greet("Hello");
		auto nmFn1 = sepFun("**************");
		nmFn1("Kapil");
		nmFn1("Gavaskar");
		nmFn1("Dravid");
		nmFn1("Sachin");
		nmFn1("Kumble");
		nmFn1("Saurav");
	}
}