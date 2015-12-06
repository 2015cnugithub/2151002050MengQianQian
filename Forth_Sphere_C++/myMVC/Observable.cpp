#include "stdafx.h"
#include "Observable.h"
#include "Observer.h"

Observable::Observable()
{
	_observer = vector<Observer*>();
	changed = false;
}


Observable::~Observable()
{
}
void Observable::addObserver(Observer * o)
{
	_observer.push_back(o);

}
void Observable::setChanged()
{
	changed = true;
}
void Observable::clearChanged()
{
	changed = false;
}
void Observable::notifyObservers()
{
	if (!changed)
		return;
	clearChanged();
	vector<Observer *>::iterator it;
	for (it = _observer.begin(); it != _observer.end(); it++)
	{
		(*it)->update(this);
	}
}