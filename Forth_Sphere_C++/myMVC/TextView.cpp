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
	cout << "圆半径为：" << s->getR() << endl;
	cout << "圆体积为:" << s->volume() << endl;
	cout << "圆表面积为:" << s->surface() << endl;
}