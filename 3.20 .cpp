#include<iostream>
#include<string>
using namespace std;
int main()
{
	string S1="ABC";
	string S2="DEF";
	string S3="GHI";
	string S4,S5;
	S4=S1;
	cout<<"S4 is "<<S4<<endl;
	S5=S1+S2;
	cout<<"S1+S2 is"<<S5<<endl;
	S5=S1+"123";
	cout<<"S1+\"123\" is "<<S5<<endl;
	if(S3>S1)
	{
		cout<<"S3>S1"<<endl;
	}
	else
	{
		cout<<"S3<S1"<<endl;
	}
	if(S4==S1)
	{
		cout<<"S4==S1"<<endl;
	}
	else
	{
		cout<<"S4<>S1"<<endl;
	}
	cout<<"请输入一个字符串给 S5:";
	cin>>S5;
	cout<<"S5 is "<<S5<<endl;
	return 0;
 } 
