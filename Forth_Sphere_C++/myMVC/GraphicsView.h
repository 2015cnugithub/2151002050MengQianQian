#pragma once
#include "Observer.h"
#include<iostream>
using namespace std;
class GraphicsView :
	public Observer
{
public:
	GraphicsView();
	~GraphicsView();
	void update(Observable * o);
};

