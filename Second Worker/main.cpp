#include <iostream>
using namespace std;
# include<cstring>
# include<iomanip>
# include<cstdlib>
# include<stdio.h>
#include<conio.h>
class Worker{
private:
    char *name;
    int age;
    char *sex;
    int pay_per_hour;
public:
    Worker(char *n,int a,char *s,int pay)
    {
        name=n;age=a;sex=s;pay_per_hour=pay;
    }
    ~Worker()
    {
        delete []name;delete []sex;
    }
    int get_pay_per_hour()   //小时工资接口
    {
        return pay_per_hour;
    }
    void getname()  //名字接口
    {
        cout<<name<<endl;
    }
    virtual double Compus_pay(double hours){}; //周薪计算成员函数
    friend ostream & operator<<(ostream & out,Worker & worker);    //标准输出运算符友元函数
};
ostream & operator<<(ostream & out,Worker& worker)
{
    switch(worker.pay_per_hour){
        case 10:
        case 20:
        case 40:out<<"HourlyWorker  "<<setw(9)<<worker.name<<setw(10)<<worker.age<<setw(12)<<worker.sex<<setw(10)<<worker.pay_per_hour;break;
        case 30:
        case 50:out<<"SalariedWorker"<<setw(9)<<worker.name<<setw(10)<<worker.age<<setw(12)<<worker.sex<<setw(10)<<worker.pay_per_hour;break;
        default:break;
    }
    return out;
}

class HourlyWorker:public Worker  //计时工人
{
public:
    HourlyWorker(char *nn,int aa,char *ss,int pp):Worker(nn,aa,ss,pp){} //构造函数
    double Compus_pay(double hours); //周薪成员函数

};
double HourlyWorker::Compus_pay(double hours)
{
        double sum1=0,a=0;
        a=Worker::get_pay_per_hour();
        if(hours<=40)
            sum1=a*hours;
        else
            sum1=a*40+1.5*a*(hours-40);
        return sum1;
}
class SalariedWorker:public Worker //计薪工人
{
    public:
    SalariedWorker(char *n,int a,char *s,int p):Worker(n,a,s,p){} //构造函数
    double Compus_pay(double hours); //周薪计算成员函数
};
double SalariedWorker::Compus_pay(double hours)
{

        double sum2=0,a=0;
        a=Worker::get_pay_per_hour();
        if(hours>=35)
            sum2=a*40;
        else
            sum2=a*hours+0.5*a*(35-hours);
        return sum2;
}
int main(){
   Worker *w[5];
   cout<<"请您依次输入3名计时工人的姓名，年龄，性别和小时工资额(10,20,40)："<<endl;
   int i=0;
   char name[5][10];
   int age=0;
   char sex[5][10];
   int pay_per=0;
    for(i=0;i<3;i++)
    {
        cin>>name[i]>>age>>sex[i]>>pay_per;;
        w[i]=new HourlyWorker(name[i],age,sex[i],pay_per);

    }

    cout<<"请您依次输入2名计薪工人的姓名，年龄，性别和小时工资额(30,50)："<<endl;
     for(i=3;i<5;i++)
    {
        cin>>name[i]>>age>>sex[i]>>pay_per;
        w[i]=new SalariedWorker(name[i],age,sex[i],pay_per);
    }
    cout<<endl;
    cout<<"============工人基本信息注册成功！============"<<endl;
    for(int j=0;j<5;j++)
        cout<<*w[j]<<endl;
     //cout<<"请选择一名工人进行查询（0~5):";
     //cout<<endl;
     char ch;
     do{
        cout<<"=================主菜单================="<<endl;
        cout<<"1.";w[0]->getname();
        cout<<"2.";w[1]->getname();
        cout<<"3.";w[2]->getname();
        cout<<"4.";w[3]->getname();
        cout<<"5.";w[4]->getname();
        cout<<"0(退出)"<<endl;
        cout<<"请选择一名工人进行查询（0~5):";
     //   ch=getche();
        cin>>ch;
        if(ch=='0')
         break;
     //   cout<<endl;
        double hours;
        cout<<"请输入工人的实际工作时数：";
        cin>>hours;
        cout<<endl;
        cout<<"===============工人基本信息==============="<<endl;
        cout<<endl;
        cout<<"工人种类"<<setw(15)<<"姓名"<<setw(12)<<"年龄"<<setw(11)<<"性别"<<setw(12)<<"薪金等级"<<setw(12)<<"周薪"<<setw(12)<<endl;
        switch(ch){
            case '0':return 0;
            case '1':cout<<*w[0]<<setw(15)<<w[0]->Compus_pay(hours)<<endl;break;
            case '2':cout<<*w[1]<<setw(15)<<w[1]->Compus_pay(hours)<<endl;break;
            case '3':cout<<*w[2]<<setw(15)<<w[2]->Compus_pay(hours)<<endl;break;
            case '4':cout<<*w[3]<<setw(15)<<w[3]->Compus_pay(hours)<<endl;break;
            case '5':cout<<*w[4]<<setw(15)<<w[4]->Compus_pay(hours)<<endl;break;
            default:break;
        }
     }while(ch!='0');
    return 0;
}