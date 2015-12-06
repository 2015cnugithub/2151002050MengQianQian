// myMVC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Controller.h"
#include "Sphere.h"
#include "TextView.h"
#include "GraphicsView.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "         << MVC演示程序 >>         " << endl;
	Sphere sphere;
	//TextView textview();
	TextView *textview = new TextView();
	GraphicsView *graphicsview = new GraphicsView();
	sphere.addObserver(textview);
	sphere.addObserver(graphicsview);
	double r;
	cout << "请您输入半径：";
	while (cin >> r)
	{
     Controller(sphere).action(r);
	}
	//
	return 0;
}

