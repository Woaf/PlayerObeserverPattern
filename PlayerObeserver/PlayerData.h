#pragma once

#include "MountType.h"

#include <optional>

struct PlayerData 
{
	float xPos;
	float yPos;
	float zPos;

	std::optional<MountType> mountType;
};

