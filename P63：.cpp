#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	private:
		double real;
		double imag;
	public:
		Complex(double r,double i);
		double abscomplex();
};
Complex::Complex(double r,double i)
{
	real=r;
	imag=i;
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
