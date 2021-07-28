#pragma once
#include "IObserver.h"

#include "PlayerData.h"

class AdultNPC : public IObserver 
{
public:
	explicit AdultNPC (float x, float y, float z);

	virtual void Subscribe (IObservable* observable) override;
	virtual void Update () override;

private:
	float xPos;
	float yPos;
	float zPos;

	IObservable* observable;

private: 
	bool WithinProximity (const PlayerData& playerData) const;
};

