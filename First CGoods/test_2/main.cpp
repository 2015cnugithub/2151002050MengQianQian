
#include<iostream>
#include<cstring>
using namespace std;

class CGoods{
private:
    long no;
    char *p_name;
    double price;
    int count; //增加count
public:
    CGoods(long newn,char *p,double newp,int newc);//构造函数
    ~CGoods()//析构函数
    {
        delete [] p_name;
    }
    CGoods(CGoods &C);//拷贝构造函数
    void show();//打印数据成员的成员函数
    int getCount()
    {
        return count;
    }
    friend void getName(CGoods C);//友元函数获取商品名称p_name
};
CGoods::CGoods(long newn, char* p, double newp,int newc)//构造函数
{
    no=newn;
   // p_name=new char[strlen(p)+1];
    //strcpy(p_name,p);
    p_name=p;
    price=newp;
    count=newc;

}
CGoods::CGoods(CGoods &C)//拷贝构造函数
{
    no=C.no;
    p_name=C.p_name;
    price=C.price;
    count=C.count;
}
void CGoods::show()
{
    cout<<"商品号:"<<no<<endl;
    cout<<"商品名:"<<p_name<<endl;
    cout<<"商品价格:"<<price<<endl;
    cout<<"商品总数："<<count<<endl;
}
void getName(CGoods C)
{
    cout<<"test function getName!"<<endl;
    cout<<C.p_name;
}
int main()
{
    long n;
    double pp;
    char str[10];
    int c;
    cout<<"请输入商品名：";
    cin>>str;
    cout<<"请输入商品号：";
    cin>>n;
    cout<<"请输入商品价格：";
    cin>>pp;
    cout<<"请输入商品总数：";
    cin>>c;
  
    CGoods good(n,str,pp,c);
    good.show();
    getName(good);
    return 0;
}