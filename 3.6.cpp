#include<iostream>
#include<cmath>
using namespace std;
class Complex{
	private:
		double real;
		double imag;
	public:
		Complex()
	    {
	    	real=0;
	    	imag=0;
		}
		void init(double r,double i)
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
};
int main()
{
	Complex A;
	A.init(1.1,2.2);
	cout<<"�����ľ���ֵ��"<<A.abscomplex()<<endl;
	return 0; 
}
