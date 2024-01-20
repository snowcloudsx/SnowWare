#pragma once
class Flight {
public:
	static inline bool enabled;
	static inline float speed;
	static inline bool blatent;
	void runModule(bool state);
	void runModuleV2();
	void onDisable();
};

