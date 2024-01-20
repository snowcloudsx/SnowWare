#include "Step.h"
#include "../../SDK/Entity/Player/Player.h"
#include "../../Mapper/Mapper.h"




void Step::runModule(float height)
{
	//"S", "F"
	jfieldID step_height = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "S", "F");
	mc.env->SetFloatField(CPlayer::getPlayer(), step_height, height);
}

void Step::onDisable()
{
	stepHeight = 0.8f;
	jfieldID step_height = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "S", "F");
	mc.env->SetFloatField(CPlayer::getPlayer(), step_height, stepHeight);
}
