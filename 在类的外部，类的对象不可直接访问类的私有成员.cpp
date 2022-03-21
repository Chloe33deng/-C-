#include<iostream>
using namespace std;
class Sample{
	private:
		int i;
	public:
		int j;
		set(int i1,int j1)
		{i1=i;j=j1;}
};
int main()
{
	Sample a;
	a.set(1,2);
	//cout<<"i="<<a.i<<endl;           //非法,类 Sample 的对象 a 不能访问类的私有成员 i 
	cout<<"j="<<a.j<<endl;
	return 0; 
}
