#include<iostream>
#include<map>
using namespace std;

namespace nm11
{
	class ISort
	{
	public:
		virtual void DoSort() = 0;
	};

	class BubbleSort :public ISort
	{

	public:
		void DoSort()
		{
			cout << "Bubble Sort" << endl;
		}
	};

	class LinearSort :public ISort
	{

	public:
		void DoSort()
		{
			cout << "Linear Sort" << endl;
		}
	};

	class Array
	{
		ISort *srt;
	public:
		void SetSort(int par)
		{
			if (10 == par)
			{
				srt = new BubbleSort();
			}
			else
			{
				srt = new LinearSort();
			}
		}
		void Sort()
		{
			srt->DoSort();
		}
	};


	void main()
	{
		Array arr;
		arr.SetSort(20);
		arr.Sort();
	}
}