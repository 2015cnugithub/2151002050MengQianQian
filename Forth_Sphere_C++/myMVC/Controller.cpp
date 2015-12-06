#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
}
Controller::Controller(Sphere sphere)
{
	this->sphere = sphere;
}
void Controller::action(double r)
{
	sphere.setR(r);
}