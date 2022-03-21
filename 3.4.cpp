#include<iostream>
using namespace std;
class Point{
	public:
		void setpoint(int a,int b)
		{
			x=a;
			y=b;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
	private:
		int x,y;
}op1,op2;
int main()
{
	op1.setpoint(1,2);
	op2.setpoint(3,4);
	int i,j;
	i=op1.getx();
	j=op1.gety();
	cout<<"op1 i="<<i<<"  op1 j="<<j<<endl;
	i=op2.getx();
	j=op2.gety();
	cout<<"op2 i="<<i<<"  op2 j="<<j<<endl;
	return 0;
}
