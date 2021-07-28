#pragma once

#include "PlayerData.h"

#include <vector>

class IObserver;

class IObservable 
{
public:
	virtual void AddSubscriber (IObserver* subscriber) = 0;
	virtual void SetNewData (const PlayerData& newPlayerData) = 0;
	virtual PlayerData GetData () = 0;

protected:
	virtual void NotifyAll () const = 0;
};
