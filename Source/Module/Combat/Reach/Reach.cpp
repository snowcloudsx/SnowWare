#include "Reach.h"
#include "../../SDK.h"
#include "../../../SDK/Entity/Player/Player.h"
#include "../../settings/settings.h"

void Reach::runModule()
{
	jclass mc_class = mc.env->GetObjectClass(SDK::getMinecraft());
	jfieldID mouseover_fid = mc.env->GetFieldID(mc_class, "s", "Lauh;");
	jobject ray = CPlayer::raytrace(settings::dist);
	mc.env->SetObjectField(SDK::getMinecraft(), mouseover_fid, ray);
	printf("Reach \n");
}
