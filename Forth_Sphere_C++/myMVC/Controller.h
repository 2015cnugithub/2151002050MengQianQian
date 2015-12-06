#pragma once
#include "Sphere.h"
class Controller
{
private:
	Sphere sphere;
public:
	Controller();
	Controller(Sphere sphere);
	void action(double r);
};

