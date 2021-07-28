#pragma once

class IObservable;

class IObserver 
{
public: 
	virtual void Subscribe (IObservable* observable) = 0;
	virtual void Update () = 0;
};
