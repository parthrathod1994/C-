#include<iostream>
using namespace std;
namespace nm11
{
	//compile time 
	constexpr int fun(int par)//c++11 onwards (relaxed c++14)
	{
		if (10 == par)
			return 5;
		return 10;
	}

	void main()
	{
		int arr[3];// = { 1,2,3 };
		int arr1[fun(10)];
	}
}