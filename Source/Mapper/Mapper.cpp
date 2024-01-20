#include "../JNI/Helper/Java.h"
#include <iostream>
#include "Mapper.h"
 
bool isForge;
bool isLunar;
bool isVanilla;
//jclass MinecraftClassVersion_1_8 = mc.env->FindClass("ave");
//jclass MinecraftClassVersion_1_7 = mc.env->FindClass("B");
//jclass MinecraftClassVersion_1_12 = ct.env->FindClass("Z");


jclass Mapper::ForgeFindClass(const char* name)
{
	if (LaunchWrapperClassLoaderClass == NULL)
	{
		LaunchWrapperClassLoaderClass = mc.env->FindClass("net/minecraft/launchwrapper/LaunchClassLoader");
		if (LaunchWrapperClassLoaderClass == NULL) return NULL;
	}

	if (FindClassMethodID == NULL)
	{
		FindClassMethodID = mc.env->GetMethodID(LaunchWrapperClassLoaderClass, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
		if (FindClassMethodID == NULL) return NULL;
	}

	if (LaunchClass == NULL)
	{
		LaunchClass = mc.env->FindClass("net/minecraft/launchwrapper/Launch");
		if (LaunchClass == NULL) return NULL;
	}

	if (ClassLoaderFieldID == NULL)
	{
		ClassLoaderFieldID = mc.env->GetStaticFieldID(LaunchClass, "classLoader", "Lnet/minecraft/launchwrapper/LaunchClassLoader;");
		if (ClassLoaderFieldID == NULL) return NULL;
	}

	if (ClassLoaderObject == NULL)
	{
		ClassLoaderObject = mc.env->GetStaticObjectField(LaunchClass, ClassLoaderFieldID);
		if (ClassLoaderObject == NULL) return NULL;
	}

	jstring jname = mc.env->NewStringUTF(name);
	jclass cls = (jclass)mc.env->CallObjectMethod(ClassLoaderObject, FindClassMethodID, jname);

	mc.env->DeleteLocalRef(jname);

	return cls;
}




void Mapper::Vanilla() {
    jclass VanillaClass = mc.env->FindClass("ave");
    if (VanillaClass != NULL && isForge == false) {
        mc.env->DeleteLocalRef(VanillaClass);
        std::cout << "Found Vanilla 1.8.9" << std::endl;
        isVanilla = true;
    }
    else if (VanillaClass == NULL) {
        std::cout << "Did not find Vanilla 1.8.9" << std::endl;
        isVanilla = false;
    }
}


bool Mapper::IsForge()
{
    jclass forgeClass = mc.env->FindClass("net/minecraftforge/common/ForgeVersion");
    if (forgeClass != NULL)
    {
        //printf("Found forge!");
        mc.env->DeleteLocalRef(forgeClass);
        isForge = true;
    }

    return isForge;
}





void Mapper::StartUp() {
    Mapper::IsForge();

   }

    

