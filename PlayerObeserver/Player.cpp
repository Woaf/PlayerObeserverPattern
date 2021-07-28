#include "Player.h"

#include "IObserver.h"

Player::Player (const std::string& playerName) :
    playerName (playerName),
    xPos (0.0f), 
    yPos (0.0f),
    zPos (0.0f), 
    mountType (std::nullopt)
{
}

void Player::AddSubscriber (IObserver* subscriber)
{
    nearbyNpcs.emplace_back (subscriber);
}

void Player::SetNewData (const PlayerData& newPlayerData)
{
    SetPosition (newPlayerData.xPos, newPlayerData.yPos, newPlayerData.zPos);
    SetWeaponType (newPlayerData.mountType);

    NotifyAll ();
}

PlayerData Player::GetData ()
{
    return {xPos, yPos, zPos, mountType};
}

void Player::SetPosition (float x, float y, float z)
{
    xPos += x;
    yPos += y;
    zPos += z;
}

void Player::SetWeaponType (const std::optional<MountType>& newMountType)
{
    mountType = newMountType;
}

void Player::NotifyAll () const
{
    for (auto& npc : nearbyNpcs) {
        npc->Update ();
    }
}
