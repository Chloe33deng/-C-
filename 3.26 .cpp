#include<iostream>
using namespace std;
class Point{
	public:
		Point(int a,int b)
		{
			x=a;
			y=b;
		}
		void print()
		{
			cout<<x<<" "<<y<<endl;
		}
	private:
		int x,y;
};
int main()
{
	Point p1(30,40);
	Point p2(p1);
	Point p3=p1;
	
	p1.print();
	p2.print();
	p3.print();
	return 0; 
}
