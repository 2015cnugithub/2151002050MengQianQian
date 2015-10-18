
#include<iostream>
#include<cstring>
using namespace std;
#include<stdio.h>
class CGoods{
private:
    long no;
    char *p_name;
    double price;
public:
    CGoods(long newn,char *p,double newp);//构造函数
    ~CGoods()//析构函数
    {
        delete [] p_name;
    }
    CGoods(CGoods &C);//拷贝构造函数
    void show();//打印数据成员的成员函数
};
CGoods::CGoods(long newn, char* p, double newp)//构造函数
{
    no=newn;
    p_name=new char[strlen(p)+1];
    strcpy(p_name,p);
    price=newp;

}
CGoods::CGoods(CGoods &C)//拷贝构造函数
{
    no=C.no;
    p_name=C.p_name;
    price=C.price;
}
void CGoods::show()
{
    cout<<"商品号:"<<no<<endl;
    cout<<"商品名:"<<p_name<<endl;
    cout<<"商品价格:"<<price;
}
int main()
{
    int i=0;
    long n;
    double pp;
    char str[10];
    cout<<"请输入商品号：";
    cin>>n;
    cout<<"请输入商品名：";
    cin>>str;
    cout<<"请输入商品价格：";
    cin>>pp;
    CGoods good(n,str,pp);
    good.show();
    return 0;
}