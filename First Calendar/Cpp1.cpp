
#include<iostream>
using namespace std;
#include <iomanip>
int gettotalnumofday(int,int);//����1��1��1������µ�һ����������
int getmonthdays(int,int);//��������м���
int getstartday(int,int);//������µ�һ�������ڼ�
int isleapyear(int);//�ж��Ƿ�Ϊ����
void printmonthtitle(int,int);
void printmonthbody(int,int);
int gettotalnumofday(int y,int m)
{
    int days;
    days=y*365+y/400+y/4-y/100;//����1��1�µ����������
    int i;
    for(i=12;i>=m;i--)
        days-=getmonthdays(y,i);//����1��1�µ����µ�һ�������
    return days;
}
int getstartday(int y,int m)//������µ�һ���������
{
    int d;
    d=gettotalnumofday(y,m);
    int dayweek;
    dayweek=(d+1)%7;//��1��1��1��Ϊ����һ
    return dayweek;
}
int getmonthdays(int y,int m) //������µ�����
{
    if(m==4||m==6||m==9||m==11)
        return 30;
    else
    {
        if(m==2)
        {
            if(isleapyear(y))
                return 29;
            else
                return 28;
        }
            else
                 return 31;
    }
}
int isleapyear(int y)
{
    if((y%4==0&&y%100!=0)||(y%400==0))
        return 1;
    else
        return 0;
}
int main()
{
    int month,year;
    cout<<"Please input the year and month:";
    cin>>year>>month;
    int dw,days;
    dw=getstartday(year,month);
    days=getmonthdays(year,month);
    printmonthtitle(year,month);
    printmonthbody(dw,days);
    return 0;
}
void printmonthtitle(int y,int m)
{
    cout<<"\n"<<endl;
	cout<<"                      "<<y<<"��"<<m<<"��"<<endl;
}
void printmonthbody(int dw,int days)
{
      int num,count,i;

    num=0;i=0;
    cout<<"\n"<<"һ"<<"\t"<<"��"<<"\t"<<"��"<<"\t"<<"��"<<"\t"<<"��"<<"\t"<<"��"<<"\t"<<"��"<<"\t"<<"\n";
    while(num<=days)
    {
        cout<<"\n";
       
        for(count=1;count<=7;count++)
        {
             while(i<dw-1)
        {
            cout<<"\t";
            i++;count++;
        }
            num=num+1;
            if(num>=1&&num<=days)
                cout<<num<<"\t";
            else
                cout<<"\t";
        }
		cout<<"\n";
    }
    cout<<"\n";
}