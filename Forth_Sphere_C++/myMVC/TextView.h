#pragma once
#include"Sphere.h"
#include "Observer.h"
#include <iostream>
using namespace std;

class TextView :
	public Observer
{
public:
	TextView();
	~TextView();
	void update(Observable * o);
};

