#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	public:
		Complex(double r=0.0,double i=0.0):real(r),imag(i)
		{  }
		~Complex()
		{
			cout<<"Destructor called."<<endl;
		}
		double abscomplex()
		{
			double t;
			t=real*real+imag*imag;
			return sqrt(t);	
		}
	private:
		double real;
		double imag;
};
int main()
{
	Complex com[3]={
	Complex(1.1,2.2),
	Complex(3.3,4.4),
	Complex(5.5,6.6)
	};
	cout<<"复数 1 的绝对值："<<com[0].abscomplex()<<endl;
	cout<<"复数 2 的绝对值："<<com[1].abscomplex()<<endl;
    cout<<"复数 3 的绝对值："<<com[2].abscomplex()<<endl;
	return 0;	
}
