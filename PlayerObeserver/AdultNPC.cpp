#include "AdultNPC.h"

#include "IObservable.h"

#include <iostream>

AdultNPC::AdultNPC (float x, float y, float z) :
	xPos (x),
	yPos (y),
	zPos (z),
	observable (nullptr)
{
}

void AdultNPC::Subscribe (IObservable* observable)
{
	this->observable = observable;
	observable->AddSubscriber (this);
}

static void ReactToSpecificMount (MountType mountType) 
{
	switch (mountType) {
		case (MountType::RAPTOR): 
			std::cout << "We could use a few of those Raptors on the farm, outlander." << std::endl;
			break;
		case (MountType::SPRINGER): 
			std::cout << "Hey! Don't you dare bring your Springer here! They will stomp our harvest!" << std::endl;
			break;
		case (MountType::SKIMMER): 
			std::cout << "Help us look for troublemakers in the cornfields. The levitation height gives you an advantage." << std::endl;
			break;
		case (MountType::JACKAL): 
			std::cout << "If your Jackal needs some water stop by the fountain." << std::endl;
			break;
		case (MountType::GRIFFON): 
			std::cout << "Could you deliver some haystacks to the hillside storage? Your Griffon would be quite capable of doing so." << std::endl;
			break;
		default: 
			break;
	}
}

static void ReactToPlayerMountType (const std::optional<MountType>& mountType)
{
	if (mountType.has_value ()) {
		ReactToSpecificMount (mountType.value ());
	} else {
		std::cout << "Well, don't just stand there - grab a shovel and help with the crops!" << std::endl;
	}
}

void AdultNPC::Update ()
{
	const PlayerData playerData = observable->GetData ();
	if (WithinProximity (playerData)) {
		ReactToPlayerMountType (playerData.mountType);
	}
}

bool AdultNPC::WithinProximity (const PlayerData& playerData) const
{
	float xDiff = xPos - playerData.xPos;
	float yDiff = yPos - playerData.yPos; 
	float zDiff = zPos - playerData.zPos;

	float dist = sqrtf (xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
	return dist < 50.0;
}
