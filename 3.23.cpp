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
	cout<<"�ں��� sqr_it�ڣ��βζ��� ob �����ݳ�Ա i ��ֵΪ��"<<ob.get_i();
	cout<<endl;
}
int main()
{
	Tr obj(10);
	cout<<"���ú��� sqr_it ǰ��ʵ�ζ��� obj �����ݳ�Ա i ��ֵΪ:";
	cout<<obj.get_i()<<endl;
	sqr_it(obj);
	cout<<"���ú��� sqr_it ��ʵ�ζ��� obj �����ݳ�Ա i ��ֵΪ��";
	cout<<obj.get_i();
	return 0; 
}
