#include<iostream>
using namespace std;
class Date{
	public:
		Date();
		Date(int y,int m,int d);
		void showDate();
	private:
		int year;
		int month;
		int day;
};
Date::Date()
{
	year=2019;
	month=6;
	day=4;
}
Date::Date(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}
inline void Date::showDate()
{
	cout<<year<<"."<<month<<"."<<day<<"."<<endl;
}
int main()
{
	Date date1;
	cout<<"date1 output:"<<endl;
	date1.showDate();
	cout<<"date2 output:"<<endl;
	Date date2(1999,12,28);
	date2.showDate();
	return 0;
}
