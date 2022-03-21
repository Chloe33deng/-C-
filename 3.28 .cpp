#include<iostream>
#include<string> 
using namespace std;
class Student{
	public:
		Student(char * name,char * stu_no1,float score1);
		~Student();
		void show();
		void show_count_sum_ave();
	private:
		char * name;
		char * stu_no;
		float score;
		int count;
		float sum;
		float ave;
}; 
Student::Student(char * name1,char * stu_no1,float score1)
{
	name=new char[strlen(name1)+1];
	strcpy(name,name1);
	stu_no=new char[strlen(stu_no1)+1];
	strcpy(stu_no,stu_no1);
	score=score1;
	++count;
	sum=sum+score;
	ave=sum/count;
}
Student::~Student()
{
	delete []name;
	delete []stu_no;
	--count;
	sum=sum-score;
}
void Student::show()
{
	cout<<"\n ������"<<name;
	cout<<"\n ѧ�ţ�"<<stu_no;
	cout<<"\n �ɼ���"<<score; 
}
void Student::show_count_sum_ave()
{
	cout<<"\n ѧ��������"<<count;
	cout<<"\n ƽ���ɼ���"<<ave; 
}
int main()
{
	Student stu1("��ɺɺ","1812001107",100);
	stu1.show();
	stu1.show_count_sum_ave();
	cout<<"\n--------------------------------\n";
	Student stu2("�׾�ͤ","1812001107",100);
	stu2.show();
	stu2.show_count_sum_ave();
	return 0;
}
