#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	public:
		Complex(double r=0.0,double i=0.0);
		double abscomplex();
	private:
		double real;
		double imag;
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
	Complex S1;
	cout<<"复数 1 的绝对值："<<S1.abscomplex()<<endl;
	Complex S2(1.1);
	cout<<"复数 2 的绝对值："<<S2.abscomplex()<<endl;
	Complex S3(1.1,2.2);
	cout<<"复数 3 的绝对值："<<S3.abscomplex()<<endl;
	return 0;
}
