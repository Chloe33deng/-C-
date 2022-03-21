#include<iostream>
using namespace std;
class Date{
	public:
		int year;
};
int main()
{
	Date d,*ptr;
	d.year=2019;
	ptr=&d;
	//cout<<ptr->year;
	//cout<<(*ptr).year;
	cout<<d.year;
	return 0;
}
