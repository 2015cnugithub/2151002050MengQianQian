#include "stdafx.h"
#include "Sphere.h"
//Sphere::Sphere(Observable *o){}
Sphere::Sphere(){}
Sphere::Sphere(double r)
{
	this->r = r;
}
double Sphere::getR()
{
	return r;
}
void Sphere::setR(double r)
{
	this->r = r;
	this->setChanged();
	this->notifyObservers();
}
double Sphere::volume()
{
	return (double)4 / (double)3 * PI * r * r * r;
}
double Sphere::surface()
{
	return 4 * PI*r*r;
}

