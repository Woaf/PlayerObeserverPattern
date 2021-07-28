#include "ChildNPC.h"

#include "IObservable.h"

#include <iostream>

void ChildNPC::Subscribe (IObservable* observable)
{
	this->observable = observable;
	observable->AddSubscriber (this);
}

static void ReactToSpecificMount (MountType mountType)
{
	switch (mountType) {
		case (MountType::RAPTOR): 
			std::cout << "Did you feed yor Raptor today?" << std::endl;
			break;
		case (MountType::SPRINGER):
			std::cout << "Wow, a real Springer! I've never seen one up so close." << std::endl;
			break;
		case (MountType::SKIMMER): 
			std::cout << "I don't know about riding a Skimmer through the desert. They are pretty handy new water though." << std::endl;
			break;
		case (MountType::JACKAL): 
			std::cout << "Doggy! Can it do tricks?" << std::endl;
			break;
		case (MountType::GRIFFON): 
			std::cout << "My word! Is that a Griffon? I've only seen them in books and paintings!" << std::endl;
			break;
		default: 
			break;
	}
}

static void ReactToPlayerMountType (const std::optional<MountType>& playerMountType)
{
	if (playerMountType.has_value ()) {
		ReactToSpecificMount (playerMountType.value ());
	} else {
		std::cout << "Haha, so you are just gonna walk all the was there?" << std::endl;
	}
}

void ChildNPC::Update ()
{
	const std::optional<MountType> playerMountType = observable->GetData ().mountType;
	ReactToPlayerMountType (playerMountType);
}
