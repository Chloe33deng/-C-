#include<iostream>
using namespace std;
class exe{
	public:
		void set_a(int a)
		{
			x=a;
		 } 
		void show_a()
		{
			cout<<x<<endl;
		}
	private:
		int x;
}; 
int main()
{
	exe ob;
	exe *p;
	ob.set_a(2);
	ob.show_a();
	p= &ob;
	p->show_a();
	(*p).show_a();
	return 0;
}





