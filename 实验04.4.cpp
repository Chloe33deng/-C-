#include<iostream>
#include<algorithm>

using namespace std; 
void jiao(char jiHe1[],int count1,char jiHe2[],int count2);
void bing(char jiHe1[],int count1 ,char jiHe2[],int count2);
void cha(char jiHe1[],int count1 ,char jiHe2[],int count2);
void diKaEr(char jiHe1[],int count1,char jiHe2[],int count2);
void output(char a[],int n);
#define N 50
int main()
{
	int choice;
	cout<<" 1.����"<<endl;
	cout<<" 2.����"<<endl;
	cout<<" 3.�"<<endl;
	cout<<" 4.�ѿ�����"<<endl;
	cin>>choice;
	if(choice==1){
		char jiHe1[N],jiHe2[N];
	int count1,count2;
	cout<<"�����뼯�� 1 ���ĸ���"<<endl;;
	cin>>count1;
	cout<<"�����뼯�� 1 ��Ԫ��"<<endl;
	for(int i=0;i<count1;i++)
	cin>>jiHe1[i];
	
	
	cout<<"�����뼯�� 2 ���ĸ���"<<endl;;
	cin>>count2;
	cout<<"�����뼯�� 2 ��Ԫ��"<<endl;
	for(int j=0;j<count2;j++)
	cin>>jiHe2[j];
	
	
	jiao(jiHe1,count1,jiHe2,count2);

	}
	else if(choice == 2){
		char jiHe1[N],jiHe2[N];
	int count1,count2;
	cout<<"�����뼯�� 1 ���ĸ���"<<endl;;
	cin>>count1;
	cout<<"�����뼯�� 1 ��Ԫ��"<<endl;
	for(int i=0;i<count1;i++)
	cin>>jiHe1[i];
	
	
	cout<<"�����뼯�� 2 ���ĸ���"<<endl;;
	cin>>count2;
	cout<<"�����뼯�� 2 ��Ԫ��"<<endl;
	for(int j=0;j<count2;j++)
	cin>>jiHe2[j];
	bing(jiHe1,count1,jiHe2,count2);
	 
	}
	else if(choice == 3){
		char jiHe1[N],jiHe2[N];
	int count1,count2;
	cout<<"�����뼯�� 1 ���ĸ���"<<endl;;
	cin>>count1;
	cout<<"�����뼯�� 1 ��Ԫ��"<<endl;
	for(int i=0;i<count1;i++)
	cin>>jiHe1[i];
	
	
	cout<<"�����뼯�� 2 ���ĸ���"<<endl;;
	cin>>count2;
	cout<<"�����뼯�� 2 ��Ԫ��"<<endl;
	for(int j=0;j<count2;j++)
	cin>>jiHe2[j];
	cha(jiHe1,count1,jiHe2,count2);
	 
	}
	else if(choice == 4){
		char jiHe1[N],jiHe2[N];
	int count1,count2;
	cout<<"�����뼯�� 1 ���ĸ���"<<endl;;
	cin>>count1;
	cout<<"�����뼯�� 1 ��Ԫ��"<<endl;
	for(int i=0;i<count1;i++)
	cin>>jiHe1[i];
	
	
	cout<<"�����뼯�� 2 ���ĸ���"<<endl;;
	cin>>count2;
	cout<<"�����뼯�� 2 ��Ԫ��"<<endl;
	for(int j=0;j<count2;j++)
	cin>>jiHe2[j];
	diKaEr(jiHe1,count1,jiHe2,count2);
	 
	}
	else return 0;
	
	system("pause");
	return 0;
}
void jiao(char jiHe1[],int count1,char jiHe2[],int count2)
{
	int num = 0;
	char a[N];
	for(int i=0;i<count1;i++)
	for(int j=0;j<count2;j++)
	{
		if(jiHe1[i]== jiHe2[j])
		a[num++]= jiHe1[i];
		
	}
	sort(a,a+num);
	cout<<"����Ϊ��";
	output(a,num);
	
}
void bing(char jiHe1[],int count1,char jiHe2[],int count2)
{
	int num1 = 0;
	int count =0;
	char b[N];
	
	for(int i=0;i<count1;i++)
	{
		b[num1++] = jiHe1[i];
	
		}
	for(int j=0;j<count2;j++){
		for(int k=0;k<count1;k++)
		{
			if(jiHe2[j] != jiHe1[k]){
				count++; 
			}
			if(count == count1) {
				b[num1++] = jiHe2[j];
			}
		}
	count = 0;
	}
sort(b,b+num1);
cout<<"����Ϊ��";
output(b,num1);
}

void output(char a[],int n)
{
	cout<<"{";
	for(int i=0;i<n-1;i++)
	cout<<a[i]<<",";
	cout<<a[n-1];
	cout<<"}";
	cout<<endl;
}

void cha(char jiHe1[],int count1,char jiHe2[],int count2)
{
	char c[N];
	int num1 = 0;
	int num = 0;
	
	for(int i=0;i<count1;i++){
		for(int j=0;j<count2;j++){
			if(jiHe1[i] != jiHe2[j]){
				num++;
				
			}
			if(num==count2){
				c[num1++]=jiHe1[i];
				
			}
		}
		num = 0;
	}
	sort(c,c+num1);
	cout<<"�Ϊ��";
	output(c,num1);
}

void diKaEr(char jiHe1[],int count1,char jiHe2[],int count2)
{
	cout<<"�ѿ�����Ϊ";
	cout<<"{";
	//cout<<"<";
	for(int i=0;i<count1;i++){
		for(int j=0;j<count2;j++){
			cout<<"<"<<jiHe1[i]<<","<<jiHe2[j]<<">";
			
		}
	}
	cout<<"}"<<endl;
}

