#pragma once
#include <vector>
using namespace std;
class Observer;
class Observable
{
private:
	bool changed;
	//	vector<Observer> obs;
	vector<Observer *> _observer;
public:
	Observable();
	~Observable();
	void addObserver(Observer * o);
	void setChanged();
	void clearChanged();
	void notifyObservers();
};

