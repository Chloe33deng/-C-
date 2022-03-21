#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	public:
		Complex(double r=0.0,double i=0.0);
		~Complex();
		double abscomplex();
	private:
		double real;
		double imag;
};
Complex::Complex(double r,double i)
{
	real=r;
	imag=i;
	cout<<"Constructor called."<<endl;
}
Complex::~Complex()
{
	cout<<"Destructor called."<<endl;
}
double Complex::abscomplex()
{
	double t;
	t=real*real+imag*imag;
	return sqrt(t);
}
int main()
{
	Complex A(1.1,2.2);
	cout<<"复数的绝对值："<<A.abscomplex()<<endl;
	return 0;
}
