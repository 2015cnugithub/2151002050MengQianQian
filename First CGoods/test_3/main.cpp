
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
    }
    CGoods(CGoods &C);//�������캯��
    void show();//��ӡ���ݳ�Ա�ĳ�Ա����
    bool operator<(CGoods &C);  //<��������غ���
    bool operator>=(CGoods &C);//>=��������غ���
};
CGoods::CGoods(long newn, char* p, double newp)//���캯��
{
    no=newn;
    p_name=new char[strlen(p)+1];
    strcpy(p_name,p);
    price=newp;

}
CGoods::CGoods(CGoods &C)//�������캯��
{
    no=C.no;
    p_name=C.p_name;
    price=C.price;
}
void CGoods::show()
{
    cout<<"��Ʒ��:"<<no<<endl;
    cout<<"��Ʒ��:"<<p_name<<endl;
    cout<<"��Ʒ�۸�:"<<price;
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