#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;
class Figure{
	friend class FigureLink;//FigureLink�����Ӳ�ͬͼ�λ���������������
	friend class Vehicle;
protected:
	int cx,cy;  // ����ͼ�ε�����λ������
	Figure *ptr;// ָ��Ҫ���������ͼ�λ��ƶ���
	Figure *next;// ָ����������һ��ͼ�λ��ƶ���	
public:
	Figure(int x,int y)
	{
		cx=x;
		cy=y;
		next=0;
	}
	virtual ~Figure(){}
	virtual void Draw()=0;//ͼ�λ��Ʋ����ӿ�
	void operator()(int dx,int dy);// Ϊ�ƶ�ͼ���޸�ͼ��λ������	
};


void Figure::operator() (int dx,int dy)
{
cx+=dx;
cy+=dy;
}

class Triangle:public Figure
{
int rightAngleFlag;//�ж��Ƿ�Ϊֱ��������
int bottomSide; //�ױ߳�
int height;//�����εĸ�
public:
	Triangle(int b,int h,int f,int x,int y):Figure(x,y)
	{
		bottomSide=b;
		height=h;
		rightAngleFlag=f;
	}
	~Triangle(){}
	void Draw();
	Figure *Insert();
};
//////////////////////////////////////
void Triangle::Draw()
{
if(rightAngleFlag==1)
{
	int points[6]={cx-bottomSide/2,cy+height/2,cx+bottomSide/2,cy+height/2,cx+bottomSide/2,cy-height/2};
    drawpoly(3,points);//������κ���
}
else
{
	int points[6]={cx-bottomSide/2,cy+height/2,cx+bottomSide/2,cy+height/2,cx-bottomSide/2,cy-height/2};
		drawpoly(3,points);
}
}
Figure *Triangle::Insert()
{
		ptr=new Triangle(bottomSide,height,rightAngleFlag,cx,cy);

        return ptr;
}

////////////////////////////////////////

class Circle:public Figure
{
	int diameter;//ֱ��
public:
	Circle(int d,int x,int y):Figure(x,y)
	{
      diameter=d;
	}
	~Circle(){}
	void Draw();
	Figure * Insert();
};
void Circle::Draw()
{
	circle(cx,cy,diameter/2);
}
Figure* Circle::Insert()
{
	ptr=new Circle(diameter,cx,cy);
	return ptr;
}
 ////////////////////////////////////
class myRectangle:public Figure
{
	int width;
	int length;
public:
	myRectangle(int w,int l,int x,int y):Figure(x,y)
	{
		width=w;
		length=l;
	}
	virtual ~myRectangle(){}
	void Draw();
	Figure *Insert();
};
void myRectangle::Draw()
{
rectangle(cx-width/2,cy-length/2,cx+width/2,cy+length/2);
}
Figure *myRectangle::Insert()
{
	ptr=new myRectangle(width,length,cx,cy);
	return ptr;
}
/////////////////////////////////////////////////
class FigureLink{
friend class Vehicle;
Figure * head;
public:
	FigureLink();
	~FigureLink();
	bool Empty();
	void Insert(Figure *FigureNode);
};
FigureLink::FigureLink()
{
	head=NULL;
}
FigureLink::~FigureLink()
{
	Figure *p=head->next;
	Figure *q;
	while(p!=0)
	{
		q=p->next;
		delete p;
		p=q;
	}
	head=NULL;
}
bool FigureLink::Empty()
{
	if(head==0)
		return TRUE;
	else
		return FALSE;
}
void FigureLink::Insert(Figure *FigureNode)
{
Figure *p=head;
if(p==0)
  head=FigureNode;
else
{
	while(p->next!=NULL)
		p=p->next;
	p->next=FigureNode;
	FigureNode->next=NULL;
}
}

/////////////////////////////////////////////////////
class Vehicle //�����������
{
	friend class FigureLink;
protected:
	FigureLink contents;
	int xstart,ystart;
	int wheel_size;
public:
	Vehicle(){}
	virtual ~Vehicle(){}
	virtual void Draw();
	virtual void Hide();
	virtual void Move(int dx,int dy);
};
void Vehicle::Draw()
{
	if(!contents.Empty())
	{
		Figure *p=contents.head;
		while(p!=0)
		{
			p->Draw();
			p=p->next;
		}
	}
}
void Vehicle::Hide()
{
Figure *p=contents.head;
while(p!=0)
{
	unsigned int sc=getcolor(); //���ص�ǰ��ͼǰ��ɫ
	setcolor(getbkcolor()); //��ȡ��ǰ��ͼ����ɫ��������Ϊ��ǰ��ͼǰ��ɫ
	p->Draw();
	setcolor(sc);
	p=p->next;
}
}
void Vehicle::Move(int dx,int dy)
{
Figure *p=contents.head;
if(!contents.Empty())
{
	while(p)
	{
     unsigned int sc=getcolor();
	 setcolor(getbkcolor());
	 p->Draw();
	 setcolor(sc);
	 p->operator()(dx,dy);
	 p->Draw();
	 p=p->next;
	}
}
}
/////////////////////////////////////////////////////
class Car:public Vehicle
{
public:
	Car(int wheel,int x,int y):Vehicle()
	{
		wheel_size=wheel;
		xstart=x;ystart=y;
     	Figure *p;
		int d=wheel_size;
		Triangle tri1(d,d,1,xstart,ystart);p=tri1.Insert();contents.Insert(p);
		Triangle tri2(d,d,0,xstart+4.5*d,ystart);p=tri2.Insert();contents.Insert(p);
	    myRectangle rec1(3.5*d,d,xstart+2.25*d,ystart);p=rec1.Insert();contents.Insert(p);
	    myRectangle rec2(8*d,d,xstart+2.25*d,ystart+d);p=rec2.Insert();contents.Insert(p);
        Circle cir1(d,xstart,ystart+2*d);p=cir1.Insert();contents.Insert(p);
	    Circle cir2(d,xstart+4.5*d,ystart+2*d);p=cir2.Insert();contents.Insert(p);
	}
	~Car(){}
};
class Truck:public Vehicle
{
public:
	Truck(int wheel,int x,int y):Vehicle()
	{
		wheel_size=wheel;
		xstart=x;ystart=y;
        Figure *p;
		int d=wheel_size;
		myRectangle rec1(9*d,4*d,xstart,ystart);p=rec1.Insert();contents.Insert(p);
	    myRectangle rec2(2*d,3*d,xstart+5.5*d+2,ystart+0.5*d);p=rec2.Insert();contents.Insert(p);
	    Circle cir1(d,xstart-3.5*d,ystart+2.5*d);p=cir1.Insert();contents.Insert(p);
	    Circle cir2(d,xstart-2.25*d,ystart+2.5*d);p=cir2.Insert();contents.Insert(p);
	    Circle cir3(d,xstart+2.25*d,ystart+2.5*d);p=cir3.Insert();contents.Insert(p);
	    Circle cir4(d,xstart+3.5*d,ystart+2.5*d);p=cir4.Insert();contents.Insert(p);
		Circle cir5(d,xstart+5.5*d+2,ystart+2.5*d);p=cir5.Insert();contents.Insert(p);

	}
	~Truck(){}
};
///////////////////////////////////////////////////////////
char mainscreen()
{
    cout<<"================Mainscreen================"<<endl;
	cout<<"1. Car"<<endl;
	cout<<"2. Truck"<<endl;
	cout<<"3. Exit"<<endl;
	char choice;
	choice=getche();
	cout<<endl;
	return choice;

}
void subscreen()
{
    char *s1="Press <S> key to start moving.";
	char *s2="Press <P> key to pause/continue moving.";
	char *s3="Press <E> key to end moving.";
	char *s4="Press <+> key to speed up.";
	char *s5="Press <-> key to speed down.";
	outtextxy(0,10,s1);
	outtextxy(0,30,s2);
	outtextxy(0,50,s3);
	outtextxy(0,70,s4);
	outtextxy(0,90,s5);

}
static int speed=1000;
void speed_up(int x)
{
speed-=x;
}
void speed_down(int x)
{
	speed+=x;
}
void delay()
{
	for(int i=0;i<speed;i++)
		for(int j=0;j<1000;j++)
		{}
}
void choose(char c1,int sign,Vehicle *x)
{
	if(c1=='p'||c1=='P')
	{
		if(sign==0)
		{
			sign=1;
			while(!kbhit()){} //�������򷵻ط���ֵ�����򷵻�0�������ļ� include<conio.h>
			char c2=getch();
			choose(c2,sign,x);
		}
		else
		{
			sign=0;
			while(!kbhit())
			{
				delay();
				x->Move(1,0);
			
			}
			char c2=getch();
			choose(c2,sign,x);
			
		}

	}
	if(c1=='+')
	{
        speed_up(200);
		while(!kbhit()) 
		{
		delay();
		x->Move(1,0);
		}
		char c2=getch();
		choose(c2,sign,x);

	}
	if(c1=='-')
	{
        speed_down(200);
		while(!kbhit()) 
		{
		delay();
		x->Move(1,0);}
		char c2=getch();
		choose(c2,sign,x);
	}
     if(c1=='E'||c1=='e') 
	 {
		 closegraph();
	 }

}
void car()
{
//    int gdriver=DETECT,gmode;	
	initgraph(1024,728);  
	Vehicle *p;
	char c1,c2;
	int sign=0;
	subscreen();
	Car c(20,50,300);
	c.Draw();
	p=&c;
	c1=getch();
	if(c1=='S'||c1=='s')
	{
		while(!kbhit()){delay();p->Move(1,0);}
		c2=getch();
		choose(c2,sign,p);
	}

}
void truck()
{
  //  int gdriver=DETECT,gmode;	
	initgraph(1024,728);  
	Vehicle *p;
	char c1,c2;
	int sign=0;
	int x,y;   
	int w; 
	subscreen();
	Truck t(20,100,300);
	t.Draw();
	p=&t;
	c1=getch();
	if(c1=='S'||c1=='s')
	{
		while(!kbhit()){delay();p->Move(1,0);}
		c2=getch();
		choose(c2,sign,p);
	 }

	

}
int main()
{
	char choice;
	while((choice=mainscreen())!='3')
	{
        switch(choice)
		{
		case '1' : car();break;
		case '2' : truck();break;
		}

	}
	return 0;
}
