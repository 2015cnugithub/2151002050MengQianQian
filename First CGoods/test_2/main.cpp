
#include<iostream>
#include<cstring>
using namespace std;

class CGoods{
private:
    long no;
    char *p_name;
    double price;
    int count; //����count
public:
    CGoods(long newn,char *p,double newp,int newc);//���캯��
    ~CGoods()//��������
    {
        delete [] p_name;
    }
    CGoods(CGoods &C);//�������캯��
    void show();//��ӡ���ݳ�Ա�ĳ�Ա����
    int getCount()
    {
        return count;
    }
    friend void getName(CGoods C);//��Ԫ������ȡ��Ʒ����p_name
};
CGoods::CGoods(long newn, char* p, double newp,int newc)//���캯��
{
    no=newn;
   // p_name=new char[strlen(p)+1];
    //strcpy(p_name,p);
    p_name=p;
    price=newp;
    count=newc;

}
CGoods::CGoods(CGoods &C)//�������캯��
{
    no=C.no;
    p_name=C.p_name;
    price=C.price;
    count=C.count;
}
void CGoods::show()
{
    cout<<"��Ʒ��:"<<no<<endl;
    cout<<"��Ʒ��:"<<p_name<<endl;
    cout<<"��Ʒ�۸�:"<<price<<endl;
    cout<<"��Ʒ������"<<count<<endl;
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
    cout<<"��������Ʒ����";
    cin>>str;
    cout<<"��������Ʒ�ţ�";
    cin>>n;
    cout<<"��������Ʒ�۸�";
    cin>>pp;
    cout<<"��������Ʒ������";
    cin>>c;
  
    CGoods good(n,str,pp,c);
    good.show();
    getName(good);
    return 0;
}