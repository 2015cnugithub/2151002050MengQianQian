#include "stdafx.h"
#include "TextView.h"


TextView::TextView()
{
}


TextView::~TextView()
{
}
void TextView::update(Observable * o)
{
	Sphere *s = (Sphere*)o;
	cout << "Բ�뾶Ϊ��" << s->getR() << endl;
	cout << "Բ���Ϊ:" << s->volume() << endl;
	cout << "Բ�����Ϊ:" << s->surface() << endl;
}