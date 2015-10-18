
#include<iostream>
using namespace std;
#include <iomanip>
int gettotalnumofday(int,int);//计算1年1月1日与该月第一天相差的天数
int getmonthdays(int,int);//计算该月有几天
int getstartday(int,int);//计算该月第一天是星期几
int isleapyear(int);//判断是否为闰年
void printmonthtitle(int,int);
void printmonthbody(int,int);
int gettotalnumofday(int y,int m)
{
    int days;
    days=y*365+y/400+y/4-y/100;//计算1年1月到该年的天数
    int i;
    for(i=12;i>=m;i--)
        days-=getmonthdays(y,i);//计算1年1月到该月第一天的天数
    return days;
}
int getstartday(int y,int m)//计算该月第一天的星期数
{
    int d;
    d=gettotalnumofday(y,m);
    int dayweek;
    dayweek=(d+1)%7;//设1年1月1日为星期一
    return dayweek;
}
int getmonthdays(int y,int m) //计算该月的天数
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
	cout<<"                      "<<y<<"年"<<m<<"月"<<endl;
}
void printmonthbody(int dw,int days)
{
      int num,count,i;

    num=0;i=0;
    cout<<"\n"<<"一"<<"\t"<<"二"<<"\t"<<"三"<<"\t"<<"四"<<"\t"<<"五"<<"\t"<<"六"<<"\t"<<"七"<<"\t"<<"\n";
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