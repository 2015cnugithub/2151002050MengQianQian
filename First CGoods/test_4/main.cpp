
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
        cout<<"delete CGoods"<<endl;
    }
    void show();//打印数据成员的成员函数
};
CGoods::CGoods(long newn, char* p, double newp)//构造函数
{
    no=newn;
    p_name=new char[strlen(p)+1];
    strcpy(p_name,p);
    price=newp;

}
void CGoods::show()
{
    cout<<"商品号:"<<no<<endl;
    cout<<"商品名:"<<p_name<<endl;
    cout<<"商品价格:"<<price<<endl;
}
class CClothes:public CGoods
{
private:
    char *p_brand;
public:
    CClothes(long n,char *p_n,double pr,char *p_b):CGoods(n,p_n,pr) //构造函数
    {
        p_brand=p_b;
    }
    ~CClothes()   //析构函数
    {
        delete [] p_brand;
        cout<<"delete CClothes"<<endl;
    }
    void uesdFor()
    {
        cout<<"clothes ues!";
    }
    void show_clo(CClothes c)
    {
        c.show();
        cout<<"商品品牌："<<p_brand<<endl;
    }
};


class CFood:public CGoods
{
private:
    char *p_brand;
public:
    CFood(long n,char *p_n,double pr,char *p_b):CGoods(n,p_n,pr) //构造函数
    {
        p_brand=p_b;
    }
    ~CFood()   //析构函数
    {
        delete [] p_brand;
        cout<<"delete CFood"<<endl;
    }
    void uesdFor()
    {
        cout<<"food ues!";
    }
    void show_foo(CFood c)
    {
        c.show();
        cout<<"商品品牌："<<p_brand<<endl;
    }
};
int main()
{
    CClothes clothes(1,"yifu",100,"jc");
    clothes.show_clo(clothes);
    CFood foo(2,"bread",10,"tl");
    foo.show_foo(foo);
    return 0;
}