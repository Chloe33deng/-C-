#include<iostream>
using namespace std;
class exam{
	public:
		exam(int n)
		{
			x=n;
		}
		int get_x()
		{
			return x;
		}
	private:
		int x;
};
int main()
{
	exam ob1[4]={11,22,33,44};
	for (int i=0;i<4;i++)
	cout<<ob1[i].get_x()<<' ';
	return 0;
}
