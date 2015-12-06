// myMVC.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Controller.h"
#include "Sphere.h"
#include "TextView.h"
#include "GraphicsView.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "         << MVC��ʾ���� >>         " << endl;
	Sphere sphere;
	//TextView textview();
	TextView *textview = new TextView();
	GraphicsView *graphicsview = new GraphicsView();
	sphere.addObserver(textview);
	sphere.addObserver(graphicsview);
	double r;
	cout << "��������뾶��";
	while (cin >> r)
	{
     Controller(sphere).action(r);
	}
	//
	return 0;
}

