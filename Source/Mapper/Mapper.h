#pragma once

class Mapper{
public:
	static inline bool isForge;
	static bool IsForge();
	static jclass ForgeFindClass(const char* name);
	static void Vanilla();
	

	static void StartUp();

private:
	inline static jclass LaunchWrapperClassLoaderClass;
	inline static jmethodID FindClassMethodID;
	inline static jclass LaunchClass;
	inline static jfieldID ClassLoaderFieldID;
	inline static jobject ClassLoaderObject;
};