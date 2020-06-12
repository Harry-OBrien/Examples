//
//  Notifications.hpp
//  Notifications
//
//  Created by Harry O'Brien on 10/06/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#ifndef Notifications_h
#define Notifications_h

#include "LinkedList.h"

namespace Util
{
template <typename T>
class Observer;

template <typename T>
class Subject
{
	// TODO: Use linked list to store connected views
	LinkedList<Observer<T>> views;
	
	T latestValue;
	
public:
	void attach(Observer<T> *obs)
	{
		views.append(obs);
	}
	
	void remove(Observer<T> *obs)
	{
		views.remove(obs);
	}
	
	void setLatestVal(T val)
	{
		latestValue = val;
		notify();
	}
	
	T getLatestVal()
	{
		return latestValue;
	}
	
	void notify()
	{
		// Return if we have no one to notify
		if(views.getElementCount() <= 0)
			return;
		
		views.moveToHead();
		
		typename LinkedList<Observer<T>>::Element* e = views.getActiveElement();
		e->store->update();
		
		while(views.hasNext()) {
			views.next();
			e = views.getActiveElement();
			e->store->update();
		}
	}
};

template <typename T>
class Observer
{
	Subject<T> *model;
	
public:
	Observer(Subject<T> *mod)
	{
		model = mod;
		model->attach(this);
	}
	
	~Observer() {
		model->remove(this);
	}
	
	virtual void update() = 0;
	
protected:
	Subject<T> *getSubject()
	{
		return model;
	}
};

} // namespace Util

#endif /* Notifications_h */
