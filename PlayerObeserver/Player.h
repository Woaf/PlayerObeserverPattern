#pragma once

#include "IObservable.h"

#include <string>
#include <list>

class Player : public IObservable
{
public:
	explicit Player (const std::string& playerName);

	virtual void AddSubscriber (IObserver* subscriber) override;
	virtual void SetNewData (const PlayerData& newPlayerData) override;
	virtual PlayerData GetData () override;

private: 
	const std::string playerName;

	float xPos;
	float yPos;
	float zPos;

	std::optional<MountType> mountType;

	std::list<IObserver*> nearbyNpcs;

private:
	void SetPosition (float x, float y, float z);
	void SetWeaponType (const std::optional<MountType>& newWeaponType);

	virtual void NotifyAll () const override;
};

