
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
    CGoods(long newn,char *p,double newp);//���캯��
    ~CGoods()//��������
    {
        delete [] p_name;
        cout<<"delete CGoods"<<endl;
    }
    void show();//��ӡ���ݳ�Ա�ĳ�Ա����
};
CGoods::CGoods(long newn, char* p, double newp)//���캯��
{
    no=newn;
    p_name=new char[strlen(p)+1];
    strcpy(p_name,p);
    price=newp;

}
void CGoods::show()
{
    cout<<"��Ʒ��:"<<no<<endl;
    cout<<"��Ʒ��:"<<p_name<<endl;
    cout<<"��Ʒ�۸�:"<<price<<endl;
}
class CClothes:public CGoods
{
private:
    char *p_brand;
public:
    CClothes(long n,char *p_n,double pr,char *p_b):CGoods(n,p_n,pr) //���캯��
    {
        p_brand=p_b;
    }
    ~CClothes()   //��������
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
        cout<<"��ƷƷ�ƣ�"<<p_brand<<endl;
    }
};


class CFood:public CGoods
{
private:
    char *p_brand;
public:
    CFood(long n,char *p_n,double pr,char *p_b):CGoods(n,p_n,pr) //���캯��
    {
        p_brand=p_b;
    }
    ~CFood()   //��������
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
        cout<<"��ƷƷ�ƣ�"<<p_brand<<endl;
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