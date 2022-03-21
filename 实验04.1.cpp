#include <iostream>
using namespace std;
class B{
public:
	virtual void f1(double x)
	{ cout<<"B::f1(double) "<<x<<endl;}
	void f2(double x)
    { cout<<"B::f2(double) "<<2*x<<endl;}
	void f3(double x)
    { cout<<"B::f3(double) "<<3*x<<endl;}	
};
class D:public B{
public:
	virtual void f1(double x)
	{ cout<<"D::f1(double) "<<x<<endl;}
    void f2(int x)
	{ cout<<"D::f1(int) "<<2*x<<endl;}
	void f3(double x)
	{ cout<<"D::f3(double) "<<x<<endl;}
};
int main()
{	D d;
	B *pb=&d;
	D *pd=&d;
	pb->f1(1.23);
	pd->f1(1.23);
	pb->f2(1.23);
	pb->f3(1.23);
	pd->f3(3.14);
	return 0;
}
