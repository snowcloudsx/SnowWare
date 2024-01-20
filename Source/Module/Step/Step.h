#pragma once


class Step {
public:
	static inline float stepHeight;
	static inline bool enabled;
	void runModule(float height);
	void onDisable();
};