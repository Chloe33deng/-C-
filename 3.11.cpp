#include<iostream>
#include<stdlib.h> 
using namespace std;
 class timer{
 	public:
 		timer()
 		{
 			seconds=0;
		 }
		 timer(char*t)
		 {
		 	seconds=atoi(t);
		 }
		 timer(int t)
		 {
		 	seconds=t;
		 }
		 timer(int min,int sec)
		 {
		 	seconds=min*60+sec;
		 }
		 int gettimer()
		 {
		 	return seconds;
		 }
		 private:
		 	int seconds;
 };
int main()
 {
 	timer a;
 	timer b(10);
 	timer c("20");
 	timer d(1,5);
 	cout<<"seconds1="<<a.gettimer()<<endl;
 	cout<<"seconds2="<<b.gettimer()<<endl;
 	cout<<"seconds3="<<c.gettimer()<<endl;
 	cout<<"seconds4="<<d.gettimer()<<endl;
 	return 0;
 }
