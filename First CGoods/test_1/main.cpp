
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
int main()
{
    int i=0;
    long n;
    double pp;
    char str[10];
    cout<<"��������Ʒ�ţ�";
    cin>>n;
    cout<<"��������Ʒ����";
    cin>>str;
    cout<<"��������Ʒ�۸�";
    cin>>pp;
    CGoods good(n,str,pp);
    good.show();
    return 0;
}