#include "Player.h"
#include "ChildNPC.h"
#include "AdultNPC.h"

#include <iostream>

static std::ostream& operator<< (std::ostream& out, const PlayerData& playerData)
{
	out << "Player position: [x: " << playerData.xPos <<
		", y: " << playerData.yPos <<
		", z: " << playerData.zPos <<
		"]";
	return out;
}

int main ()
{
	IObservable* player = new Player ("ElyxTheLynx");
	std::cout << player->GetData () << std::endl;

	IObserver* childNPC1 = new ChildNPC ();
	childNPC1->Subscribe (player);
	IObserver* adultNPC1 = new AdultNPC (10.f, 30.f, 0.f);	// within player proximity
	adultNPC1->Subscribe (player);
	IObserver* adultNPC2 = new AdultNPC (40.f, 140.f, 0.f); // outside of player proximity
	adultNPC2->Subscribe (player);

	player->SetNewData ({0.0f, 0.0f, 0.0f, MountType::RAPTOR});
	player->SetNewData ({0.0f, 0.0f, 0.0f, MountType::SPRINGER});
	player->SetNewData ({0.0f, 0.0f, 0.0f, MountType::SKIMMER});
	player->SetNewData ({0.0f, 0.0f, 0.0f, MountType::JACKAL});
	player->SetNewData ({0.0f, 0.0f, 0.0f, MountType::GRIFFON});

	return 0;
}