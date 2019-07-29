#include<iostream>
using namespace std;

namespace nm34
{
	class CComplex
	{
		double _real = 0.0;//modern c++ member initialization
		double _imag = 0.0;
	public:
		CComplex() = default;//modern c++ default functions
		CComplex(double real, double imag) :_real(real), _imag(imag)
		{
			//
		}
		/*CComplex AddComplex(CComplex par)
		{
			CComplex temp;
			temp._real = this->_real + par._real;
			temp._imag = this->_imag + par._imag;
			return temp;
		}*/
		/*CComplex AddComplex(CComplex par)
		{
			return CComplex(this->_real + par._real, this->_imag + par._imag);
		}*/
		CComplex AddComplex(CComplex par)
		{
			return { this->_real + par._real, this->_imag + par._imag };//modern c++ onwards
		}
		void Display()
		{
			cout << _real << ((_imag >= 0.0) ? "+" : "") << _imag << "i" << endl;
		}

	};

	void main()
	{
		CComplex c1(11.2, 12.4);
		CComplex c2(12.3, -34.6);
		c1.Display();
		c2.Display();
		cout << "______________________\n";
		CComplex c3 = c1.AddComplex(c2);
		c3.Display();
	}
}