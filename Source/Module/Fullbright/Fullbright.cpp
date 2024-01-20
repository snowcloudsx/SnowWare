#include "Fullbright.h"
#include "../SDK.h"


inline bool reset = false;


void Fullbright::runModule()
{
	jclass mcc = mc.env->GetObjectClass(SDK::getMinecraft());
	jfieldID gmfid = mc.env->GetFieldID(mcc, "t", "Lavh;");
	jobject gmobj = mc.env->GetObjectField(SDK::getMinecraft(), gmfid);

	jclass gmclass = mc.env->GetObjectClass(gmobj);
	jfieldID gammafid = mc.env->GetFieldID(gmclass, "aJ", "F");
	mc.env->SetFloatField(gmobj, gammafid, (jfloat)1000.0);
}



void Fullbright::onDisable()
{
	jclass mcc = mc.env->GetObjectClass(SDK::getMinecraft());
	jfieldID gmfid = mc.env->GetFieldID(mcc, "t", "Lavh;");
	jobject gmobj = mc.env->GetObjectField(SDK::getMinecraft(), gmfid);

	jclass gmclass = mc.env->GetObjectClass(gmobj);
	jfieldID gammafid = mc.env->GetFieldID(gmclass, "aJ", "F");

	if(reset = false)
		mc.env->SetFloatField(gmobj, gammafid, (jfloat)100.0);
		reset = true;
}
