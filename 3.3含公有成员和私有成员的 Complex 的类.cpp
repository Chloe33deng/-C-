#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	private:
		double real;
		double imag;
	public:
		void init(double r,double i)
		{
			real=r;
			imag=i;
		}
		double abscomplex()
		{
			double t;
			t = real*real+imag*imag;
			return sqrt(t);
		}
};
int main()
{
	Complex A;
	A.init(1.1,2.2);
	cout<<"复数类Complex的绝对值:"<<A.abscomplex()<<endl;
	return 0; 
}

























