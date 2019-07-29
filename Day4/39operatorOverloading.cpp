#include<iostream>
using namespace std;
namespace nm39
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
		CComplex operator+(CComplex par)
		{
			return CComplex(this->_real + par._real, this->_imag + par._imag);
		}
		friend ostream& operator<<(ostream &os, CComplex & par)
		{
			os << par._real << ((par._imag >= 0.0) ? "+" : "") << par._imag << "i" << endl;
			return os;
		}
	};

	void main()
	{
		CComplex c1(11.2, 12.4);
		CComplex c2(12.3, -34.6);
		//	operator<<(cout,c1 );
			//operator<<(cout,c2);
		cout << "______________________\n";
		CComplex c3 = c1 + c2; //c1.operator+(c2);
		//CComplex c4 = c1 - c2;
		//operator<<(cout, c3) << "India is great" << endl;
		cout << c3 << endl;


	}
}