#pragma once
#include "Observable.h"
#define PI 3.14
class Sphere :
	public Observable
{
private:
	double r;
public:
	//Sphere(Observable *o);
	Sphere();
	Sphere(double r);
	double getR();
	void setR(double r);
	double volume();
	double surface();
};

