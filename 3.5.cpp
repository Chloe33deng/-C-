#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	public:
		Complex(double r,double i)
		{
			real=r;
			imag=i;
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
	Complex A(1.1,2.2);
	cout<<"�����ľ���ֵ��"<<A.abscomplex()<<endl;
	return 0;
}
