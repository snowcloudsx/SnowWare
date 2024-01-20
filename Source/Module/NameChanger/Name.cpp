#include "Name.h"
#include "../Cheat.h"
#include "../../SDK/Entity/Player/Player.h"

void NameChanger::runModule()
{
	setName(NameChanger::name);
}

void NameChanger::setName(char* Name)
{


	if (cheats::setDisplayNameTagMethodID == NULL)
	{
		cheats::setDisplayNameTagMethodID = mc.env->GetMethodID(CPlayer::getPlayerClass(), "a", "(Lnet/minecraft/util/IChatComponent;)V");
		if (cheats::setDisplayNameTagMethodID == NULL) return;
	}

	mc.env->CallVoidMethod(CPlayer::getPlayerClass(), cheats::setDisplayNameTagMethodID, Name);
}