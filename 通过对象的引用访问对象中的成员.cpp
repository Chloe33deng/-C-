#include<iostream>
using namespace std;
class Date{
	public:
		int year;
};
int main()
{
	Date d1;
	d1.year=2019;
	Date &d2=d1;
	cout<<d1.year;
	cout<<d2.year;
	return 0;
 }  
