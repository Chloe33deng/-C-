#include<iostream>
using namespace std;
class Point{
	public:
		inline void setpoint(int,int);
	    inline int getx();
	    inline int gety();
	private:
		int x,y;	
}; 
inline void Point::setpoint(int a,int b)
{
	x=a;
	y=b;
} 
inline  int Point::getx()
{
	return x;
}
inline int Point::gety()
{
	return y;
}
int main()
{
	Point op1,op2;
	int i,j;
	op1.setpoint(1,2);
	op2.setpoint(3,4);
	i=op1.getx();
	j=op1.gety();
	cout<<"op1 i="<<i<<" op1 j="<<j<<endl;
	i=op2.getx();
	j=op2.gety();
	cout<<"op2 i="<<i<<" op2 j="<<j<<endl; 
	return 0;
}
