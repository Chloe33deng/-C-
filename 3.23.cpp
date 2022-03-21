#include<iostream>
using namespace std;
class Tr{
	public:
		Tr(int n)
		{
			i=n;
		}
		void set_i(int n)
		{
			i=n;
		}
		int get_i()
		{
			return i;
		}
	private:
		int i;
};
void sqr_it(Tr &ob)
{
	ob.set_i(ob.get_i()*ob.get_i());
	cout<<"在函数 sqr_it内，形参对象 ob 的数据成员 i 的值为："<<ob.get_i();
	cout<<endl;
}
int main()
{
	Tr obj(10);
	cout<<"调用函数 sqr_it 前，实参对象 obj 的数据成员 i 的值为:";
	cout<<obj.get_i()<<endl;
	sqr_it(obj);
	cout<<"调用函数 sqr_it 后，实参对象 obj 的数据成员 i 的值为：";
	cout<<obj.get_i();
	return 0; 
}
