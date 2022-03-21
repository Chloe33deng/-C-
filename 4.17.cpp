#include<iostream>
using namespace std;
class Base{                                        //声明基类 Base 
	public:
		Base(int sa)
		{
			a=sa;
			cout<<"Constructing Base"<<endl;
		}
		private:
			int a;
};
class Base1:virtual public Base{                  //声明类 Base 是 Base1 的虚基类 
	public:
		Base1(int sa,int sb):Base(sa)             //在此，必须缀上对类 Base 构造函数的调用 
		{
			b=sb;
			cout<<"Constructing Base1"<<endl; 
		}
		private:
			int b;
};
class Base2:virtual public Base{                 //声明类 Base 是 Base2 的虚基类 
	public:
		Base2(int sa,int sc):Base(sa)            //在此，必须缀上对类 Base 构造函数的调用 
		{
			c=sc;
			cout<<"Constructing Base2"<<endl;
		}
		private:
			int c;
};
class Derived:public Base1,public Base2{        //Derived 是 Base1 和 Base2 的共同派生类，是 Base 的间接派生类 
	public:
		Derived(int sa,int sb,int sc,int sd):
			Base(sa),Base1(sa,sb),Base2(sa,sc)  //在此，必须缀上对类 Base 构造函数的调用 
			{
				d=sd;
				cout<<"Constructing Derived"<<endl;
			 } 
			 private:
			 	int d;
};
int main()
{
	Derived obj(2,4,6,8);
	return 0;
}
