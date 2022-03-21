#include<iostream>
#include<string>
using namespace std;

class Time{
	public:
		Time(int h=0,int m=0,int s=0);
		Time operator+(Time&);
		void display(string);
	private:
		int hours;
		int minutes;
		int seconds;
};
Time::Time(int h,int m,int s)
{
	hours=h;
	minutes=m;
	seconds=s;
}
Time  Time::operator+(Time&t1)
{
	Time p;
	p.seconds=seconds+t1.seconds;
	int temp=p.seconds;
	
	p.seconds=temp%60;
	
	p.minutes=minutes+t1.minutes+temp/60;
	temp=p.minutes;
	
	
	p.minutes=temp%60;
	p.hours=hours+t1.hours+temp/60;
	return p;
 } 
 void Time::display(string s)
 {
 	cout<<s<<hours<<":"<<minutes<<":"<<seconds<<endl;
 }
 int main()
 {
 	int h,m,s;
 	do
 	{
 		cout<<"输入第一个时间时分秒"<<endl;
 		cin>>h>>m>>s;
	 }
	 while(h<0||m<0||m>59||s<0||s>59);
	 Time t(h,m,s);
	 do
	 {
	 	cout<<"输入第二个时间时分秒"<<endl;
		cin>>h>>m>>s;
	  } 
	while(h<0||m<0||m>59||s<0||s>59);
	Time T(h,m,s),t_total;
	t_total=t+T;
	t_total.display("输入结果(时/分/秒):");
	return 0;
	  
 }
