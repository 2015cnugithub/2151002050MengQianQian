#pragma once
class Observable;

class Observer
{
public:
	Observer();
	virtual void update(Observable *o){}
protected:
	Observable *_observable;
};

