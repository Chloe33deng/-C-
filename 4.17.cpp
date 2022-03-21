#include<iostream>
using namespace std;
class Base{                                        //�������� Base 
	public:
		Base(int sa)
		{
			a=sa;
			cout<<"Constructing Base"<<endl;
		}
		private:
			int a;
};
class Base1:virtual public Base{                  //������ Base �� Base1 ������� 
	public:
		Base1(int sa,int sb):Base(sa)             //�ڴˣ�����׺�϶��� Base ���캯���ĵ��� 
		{
			b=sb;
			cout<<"Constructing Base1"<<endl; 
		}
		private:
			int b;
};
class Base2:virtual public Base{                 //������ Base �� Base2 ������� 
	public:
		Base2(int sa,int sc):Base(sa)            //�ڴˣ�����׺�϶��� Base ���캯���ĵ��� 
		{
			c=sc;
			cout<<"Constructing Base2"<<endl;
		}
		private:
			int c;
};
class Derived:public Base1,public Base2{        //Derived �� Base1 �� Base2 �Ĺ�ͬ�����࣬�� Base �ļ�������� 
	public:
		Derived(int sa,int sb,int sc,int sd):
			Base(sa),Base1(sa,sb),Base2(sa,sc)  //�ڴˣ�����׺�϶��� Base ���캯���ĵ��� 
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
