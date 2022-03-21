#include<iostream>
using namespace std;

const int MAX=50;
class set
{
public:
	set();
	void input();
	int length();
	void disp();
	set operator+(set s1);
	set operator-(set s1);
	set operator*(set s1);
protected:
	int len;
	int s[MAX];	
};

set::set()
{
	len=0;
	for(int i=0;i<MAX;i++)
	{
		s[i]=0;
	}
}

void set::input()
{
	cout<<"���뼯�ϳ��ȣ�"<<endl;
	cin>>len;
	cout<<"����Ԫ�أ�"<<endl;
	for(int i=0;i<len;i++)
	{
		cin>>s[i];
	}
}
int set::length()
{
	return len;
}
void set::disp()
{
	if(0==len)
	{
		cout<<"��������ǿռ���"<<endl;
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			cout<<s[i]<<" ";	
		}	
		cout<<endl;
	}
}
set set::operator+(set s1)
{
	int i,j,m;
	for(i=0;i<len;i++)
	{
		m=0;
		for(j=0;j<s1.len;j++)
		{
			if(s[i]==s1.s[j])
			{
				m=1;
			}
			else
			{continue;}
		}
		if(0==m)
		{
			s1.s[s1.len++]==s[i];
		}
	}
	return s1;
}
set set::operator-(set s1)
{
	set m;
	int i,j,k;
	for(i=0;i<len;i++)
	{
		k=0;
		for(j=0;j<s1.len;j++)
		{
			if(s[i]==s1.s[j])
			{
				k=1;
			}
			else
			{continue;}
		}
		if(0==k)
		{
			m.s[m.len++]=s[i];
		}
	}
	return m;
}
set set::operator*(set s1)
{
	set m;
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=0;j<s1.len;j++)
		{
			if(s[i]==s1.s[j])
			{
				m.s[m.len++]=s[i];
			}
			else
			{continue;}
		}
	}
	return m;
}

int main()
{
	set s1;
	s1.input();
	
	set s2;
	s2.input();
	
	cout<<"s1��s2�Ĳ���Ϊ��";
	set s;
	s=s1+s2;
	s.disp();
	cout<<"s1��s2�ĲΪ��";
	s=s1-s2;
	s.disp();
	cout<<"s1��s2�Ľ���Ϊ��";
	s=s1*s2;
	s.disp();
	return 0;
}
