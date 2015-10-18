
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
    bool operator<(CGoods &C);  //<运算符重载函数
    bool operator>=(CGoods &C);//>=运算符重载函数
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
bool CGoods::operator <(CGoods& C)
{
    if(this->price>C.price)
        return 1;
    else
        return 0;
}
bool CGoods::operator >=(CGoods& C)
{
    if(this->price>=C.price)
        return 1;
    else
        return 0;
}
int main()
{
    CGoods p1(1,"milk",5);
    CGoods p2(2,"juice",10);
    if(p1>=p2)
        p1.show();
    else
        p2.show();
    return 0;
}