#include "Minecraft.h"
#include "../../JNI/Helper/Java.h"
#include "../../Module/SDK.h"


Minecraft::Minecraft(jobject obj)
{
	CurrentObject = obj;
	
}


void Minecraft::setTimer(float value) {
	jfieldID timerObjfid = mc.env->GetFieldID(SDK::getMinecraftClass(), "Y", "Lavl;");
	if (timerObjfid == NULL) {
		printf("Error 1\n");
		return;
	}
	jobject timerObj = mc.env->GetObjectField(SDK::getMinecraft(), timerObjfid);
	if (timerObj == NULL) {
		printf("Error 2\n");
		return;
	}
	jclass timerClass = mc.env->FindClass("avl");
	if (timerClass == NULL) {
		printf("Error 3\n");
		return;
	}
	jfieldID timerSpeedfid = mc.env->GetFieldID(timerClass, "d", "F");
	if (timerClass == NULL) {
		printf("Error 4\n");
		return;
	}
	mc.env->SetFloatField(timerObj, timerSpeedfid, value);
	float timerVal = mc.env->GetFloatField(timerObj, timerSpeedfid);
	// std::cout << timerVal << std::endl;

	mc.env->DeleteLocalRef(timerObj);
	mc.env->DeleteLocalRef(timerClass);
}