#include<iostream>
using std::cout;
using std::endl;

class CA
{
public:
	void nFun()
	{
		cout << "CA N-Fun" << endl;
	}
	virtual void vFun()
	{
		cout << "CA V-Fun" << endl;
	}
};
class CB :public CA
{
public:
	void nFun()
	{
		cout << "CB N-Fun" << endl;
	}
	virtual void vFun()
	{
		cout << "CB V-Fun" << endl;
	}
};

void main()
{
	CB objCb;
	CA *ptrCA = &objCb;//LSP (Liskov's substitution principle)
	ptrCA->nFun();
	ptrCA->vFun();
}