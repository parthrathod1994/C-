#include<iostream>
using namespace std;

namespace nm40
{
	class CComplex
	{
		double _real;
		double _imag;
	public:
		CComplex() :_real(0.0), _imag(0.0)
		{
		}
		CComplex(double real, double imag) :_real(real), _imag(imag)
		{
		}
		CComplex operator+(CComplex& par)
		{
			return CComplex(this->_real + par._real, this->_imag + par._imag);
		}
		CComplex operator+(int  par)
		{
			return CComplex(this->_real, this->_imag + par);
		}
		CComplex operator-(CComplex &par)
		{
			return CComplex(this->_real - par._real, this->_imag - par._imag);
		}
		explicit operator double()
		{
			return _real + _imag;
		}
		friend ostream& operator<<(ostream &os, CComplex & par)
		{
			os << par._real << ((par._imag >= 0.0) ? "+" : "") << par._imag << "i" << endl;
			return os;
		}
		friend CComplex operator+(int par, CComplex & cmpPar)
		{
			return CComplex(cmpPar._real + par, cmpPar._imag);
		}
	};

	//------------------------------------
	void main()
	{
		CComplex c1(11.2, 12.4);
		CComplex c2(12.3, -34.6);
		CComplex c3 = c1 + c2;
		CComplex c4 = c1 + 10;//10 to be added to imaginary
		CComplex c5 = c1 - c2;
		CComplex c6 = 10 + c3;//10 to be added to real
		cout << c1 << c2 << c3 << c4 << c5 << c6 << endl;
		//double magnitude = c3;
		double magnitude1 =(double) c3;
	}
}