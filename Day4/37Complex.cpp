#include<iostream>
using namespace std;
namespace nm37
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
		friend ostream& operator<<(CComplex & par, ostream &os)
		{
			os << par._real << ((par._imag >= 0.0) ? "+" : "") << par._imag << "i" << endl;
			return os;
		}
	};

	void main()
	{
		CComplex c1(11.2, 12.4);
		CComplex c2(12.3, -34.6);
		operator<<(c1, cout);
		operator<<(c2, cout);
		cout << "______________________\n";
		CComplex c3 = c1.operator+(c2);
		operator<<(c3, cout) << "India is great" << endl;
	}
}
