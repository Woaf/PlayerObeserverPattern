#pragma once
#include "IObserver.h"

class ChildNPC : public IObserver 
{
public:
	virtual void Subscribe (IObservable* observable) override;

	virtual void Update () override;

private:
	IObservable* observable;
};

