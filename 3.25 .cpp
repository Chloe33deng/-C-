#include<iostream>
using namespace std;
class Point{
	public:
		Point(int a,int b)
		{
			x=a;
			y=b;
		}
		Point(const Point  &p)
		{
			x=2*p.x;
			y=2*p.y;
		}
		void print()
		{
			cout<<x<<"  "<<y<<endl;
		}
	private:
		int x,y;
};
int main()
{
	Point p1(30,40);
	Point p2(p1);
	p1.print();
	p2.print() ;
	return 0;
}
